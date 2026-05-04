from flask import Flask, request, render_template_string, jsonify
import pandas as pd

app = Flask(__name__)

# This is a basic HTML template with a text box and a submit button
HTML_FORM = '''
    <h1>Enter player name to search in data</h1>
    <form action="/search" method="POST">
        <input type="text" name="user_input" placeholder="Type some name here">
        <input type="submit" value="Search">
    </form>
'''
#take data from database
def load_data():
    try:
        df = pd.read_csv('data.csv')
        df = df.where(pd.notna(df), None)
        return df
    except:
        print('no file found')
        return None

#first page
@app.route('/')
def home():
    return render_template_string(HTML_FORM)

#after search the name of player
@app.route('/search', methods=['POST'])
def get_player():
    try:
        df = load_data()
        name = request.form.get('user_input')
        result = df[df['player'].str.lower() == name.lower()]

        #return all columns of that player
        if result.empty:
            return jsonify({'error': f'player {name} not found'}), 404

        return jsonify(result.to_dict(orient='records')[0])
    except:
        #if no player found
        print('no player found')
        return None

if __name__ == '__main__':
    app.run(debug=True)
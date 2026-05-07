from flask import Flask, request, jsonify, render_template_string
import pandas as pd
import unicodedata

app = Flask(__name__)

# This is a basic HTML template with a text box and a submit button
HTML_FORM = '''
    <h1>Enter player name to search in data</h1>
    <form action="/data" method="POST">
        <input type="text" name="user_input" placeholder="Type some name here">
        <input type="submit" value="Search">
    </form>
'''
#take data from database
def load_data():
    try:
        df = pd.read_csv('./data/data.csv')
        df = df.where(pd.notna(df), None)
        df = df.drop(columns='Unnamed: 0')
        return df
    except:
        print('no file found')
        return None

#first page
@app.route('/')
def home():
    return render_template_string(HTML_FORM)

#after search the name of player
@app.route('/data', methods=['POST'])
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


# ===== 🔥 NORMALIZE (FIX TÊN CÓ DẤU) =====
def normalize(text):
    return ''.join(
        c for c in unicodedata.normalize('NFD', str(text))
        if unicodedata.category(c) != 'Mn'
    ).lower()

# ===== API: GET PLAYER LIST =====
@app.route('/players', methods=['GET'])
def get_players():
    df = load_data()
    players = df['player'].dropna().unique().tolist()
    return jsonify(players)

# ===== API: SEARCH PLAYER =====
@app.route('/search', methods=['POST'])
def get_playerss():
    df = load_data()
    name = request.form.get('user_input')

    name_norm = normalize(name)

    df['player_norm'] = df['player'].apply(normalize)

    result = df[df['player_norm'].str.contains(name_norm, na=False)]

    if result.empty:
        return jsonify({'error': 'not found'}), 404

    return jsonify(result.iloc[0].to_dict())

# ===== RUN =====
if __name__ == '__main__':
    app.run(debug=True, use_reloader=False)
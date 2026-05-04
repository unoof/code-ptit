import pandas as pd
from process_data import load_data

def main():
    #take data from team.csv
    data_all = load_data('team.csv')

    #take only the numeric columns
    max_idx = data_all.select_dtypes(include=['number']).idxmax()

    #take team with max value in each columns
    top = data_all.loc[max_idx, 'team'].values

    #return a Series of the columns + the team with max value in to a csv file
    result = pd.DataFrame({
        'stat':max_idx.index,
        'team':top
    })
    
    result.fillna('N/a').to_csv('max.csv', index=False, header=False)




if __name__ == '__main__':
    main()
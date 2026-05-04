import pandas as pd
from process_data import load_data

all_team = ['Arsenal', 'Aston Villa', 'Bournemouth', 'Brentford', 'Brighton', 'Burnley', 'Chelsea', 'Crystal Palace', 'Everton',
            'Fulham', 'Leeds United', 'Liverpool', 'Manchester City', 'Manchester Utd', 'Newcastle United', 'Nottingham Forest',
            'Sunderland', 'Tottenham Hotspur', 'West Ham United', 'Wolves']

def main():
    #load all data
    data_all = load_data('data.csv')

    #remove unnecessary columns
    remove_col = ['Unnamed: 0','player','nationality','position','age','birth_year']
    data = data_all.drop(columns=remove_col)
    
    #make separate file to predict the best team
    data.to_csv('raw_team.csv', index=False)

    data = data.groupby('team')

    #find the mean of all teams
    all_team_means = data.mean(numeric_only=True).round(2)
    all_team_means = all_team_means.rename(columns={name:f'mean {name}' for name in list(all_team_means)})

    #find the median of all teams
    all_team_medians = data.median(numeric_only=True).round(2)
    all_team_medians = all_team_medians.rename(columns={name:f'median {name}' for name in list(all_team_medians)})

    #find the standard deviation of all teams
    all_team_std = data.std(numeric_only=True).round(2)
    all_team_std = all_team_std.rename(columns={name:f'std {name}' for name in list(all_team_std)})

    #write to the team.csv file
    total = pd.concat([all_team_means, all_team_medians, all_team_std], axis=1)
    total.fillna('N/a').to_csv('team.csv')

if __name__ == '__main__':
    main()
from process_data import load_data

def main():
    #load the raw team file
    data_all = load_data('raw_team.csv')

    #separate the weight of each columns to calculate the value of each team
    #the pos one have the weight of +1
    pos = [
        'goals', 'assists', 'gk_saves', 'gk_wins', 'gk_clean_sheets', 
        'gk_pens_saved', 'shots_on_target', 'fouled', 'crosses', 
        'interceptions', 'tackles_won', 'plus_minus'
    ]

    #the nega one have the weight of -1
    nega = [
        'cards_yellow', 'cards_red', 'gk_goals_against', 'gk_losses', 
        'own_goals', 'fouls', 'offsides', 'pens_conceded'
    ]
    data_all[nega] = data_all[nega] * -1

    #sum of all columns of each team in a Series var
    team_ranking = data_all.groupby('team')[pos + nega].sum().sum(axis=1)

    #rename the value for easy reading then write to a csv file
    team_ranking = team_ranking.rename("score")
    team_ranking = team_ranking.sort_values(ascending=False)
    team_ranking.to_csv('rank.csv')



if __name__ == '__main__':
    main()
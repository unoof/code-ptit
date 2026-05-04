import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.decomposition import PCA

#just a load data for other file to use 
def load_data(file):
    try:
        df = pd.read_csv(file, na_values=['N/a']).fillna(0)
        return df
    except FileNotFoundError:
        print('no file found')
        return None

#separate gk and other roles
def process():
    #read the data.csv file
    data_all = load_data('data.csv')
    #remove some unnecessary columns
    remove_col = ['Unnamed: 0','nationality','team','age','birth_year']
    data = data_all.drop(columns=remove_col)

    #use only some columns
    gk_cols = [
        'player',
        'minutes_90s',
        'gk_save_pct',
        'gk_goals_against_per90',
        'gk_clean_sheets_pct',
        'gk_wins',
        'gk_ties',
        'gk_losses',
        'gk_shots_on_target_against',
        'plus_minus_per90',
        'points_per_game',
        'gk_pens_att',
        'gk_pens_save_pct'
    ]

    outfield_cols = [
        'player', 'position',
        'minutes_90s',
        'goals_per90',
        'assists_per90',
        'shots_per90',
        'shots_on_target_per90',
        'goals_per_shot',
        'crosses',
        'fouled',
        'offsides',
        'interceptions',
        'tackles_won',
        'fouls',
        'cards_yellow',
        'cards_red',
        'plus_minus_per90',
        'points_per_game'
    ]

    #take only some columns
    gk = data[data['position'].str.contains('GK', na=False)].copy()
    gk = gk.reindex(columns=gk_cols)

    outfield = data[~data['position'].str.contains('GK', na=False)].copy()
    outfield = outfield.reindex(columns=outfield_cols)

    return gk, outfield

class pca:
    def apply_pca(scaled_data, component):
        #using Principal Component Analysis to reduce the dimension of the data
        pca = PCA(n_components=component)
        pca_data = pca.fit_transform(scaled_data)

        #just a check
        total_variance = sum(pca.explained_variance_ratio_) * 100
        print(f"Captured {total_variance:.2f}% of total variance with {component} components.")
        return pca_data


    def plot_2d(pca_data, cluster_labels, title="Player Clusters"):
        plt.figure(figsize=(10, 7))
        
        #plot the first two columns of the PCA data
        #c=cluster_labels assigns a different color to each group
        scatter = plt.scatter(pca_data[:, 0], pca_data[:, 1], 
                            c=cluster_labels+1, cmap='viridis', s=50, alpha=0.7)
        
        # Add a color legend so we know which color is which cluster
        legend = plt.legend(*scatter.legend_elements(), title="Clusters")
        plt.gca().add_artist(legend)
        
        plt.xlabel('Principal Component 1')
        plt.ylabel('Principal Component 2')
        plt.title(title)
        plt.grid(True, linestyle='--', alpha=0.6)
        plt.show()


    def plot_3d(pca_data, cluster_labels, title='Player Clusters'):
        fig = plt.figure(figsize=(10, 7))
        #add 3d to the plot
        ax = fig.add_subplot(111, projection='3d')

        #plot the first two columns of the PCA data
        #c=cluster_labels assigns a different color to each group
        scatter = ax.scatter(
            pca_data[:, 0], pca_data[:, 1], pca_data[:, 2],
            c=cluster_labels+1, cmap='viridis', s=50, alpha=0.7
        )
        
        # Add a color legend so we know which color is which cluster
        legend = plt.legend(*scatter.legend_elements(), title="Clusters")
        plt.gca().add_artist(legend)

        ax.set_xlabel('Principal Component 1')
        ax.set_ylabel('Principal Component 2')
        ax.set_zlabel('Principal Component 3')
        ax.set_title(title)
        plt.show()
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import silhouette_score
import matplotlib.pyplot as plt
from process_data import process, pca


def elbow(scaled):
    #find the best clusters between 1-10 clusters
    inertias = []
    ks = range(1, 11)

    for k in ks:
        #test each cluster
        kmeans = KMeans(n_clusters=k, random_state=42, n_init = 10)
        kmeans.fit(scaled)
        inertias.append(kmeans.inertia_)
    
    #find the best k
    point = 0
    best = 0
    for i in range(1, len(inertias)-1):
        if (inertias[i-1] - inertias[i]) - (inertias[i] - inertias[i+1])  > best:
            best = (inertias[i-1] - inertias[i]) - (inertias[i] - inertias[i+1])
            point = i
    point += 1

    #plot the data to visualize it

    plt.figure(figsize=(8, 4))
    plt.plot(ks, inertias, 'bo-')
    plt.axvline(
        x=point,
        color='red',
        linestyle='--',
        linewidth=1.5,
        label=f'Best at k={point}'
    )
    plt.xlabel('Number of Clusters (k)')
    plt.ylabel('Inertia')
    plt.title('Elbow Method for Optimal k')
    plt.show()
    return point

def silhouette(scaled):
    #save all the scores and the best scores with the best clusters
    scores = []
    best_score = -1
    best_k = 1
    ks = range(2, 11)

    for k in ks:
        #try all the clusters in range of 2-10
        kmeans = KMeans(n_clusters=k, random_state=42, n_init=10)
        labels = kmeans.fit_predict(scaled)
        score = silhouette_score(scaled, labels)
        scores.append(score)
        if score > best_score:
            #if we see a better scores then change the k to that scores_k
            best_score = score
            best_k = k

    #plot the data to visualize it
    plt.figure(figsize=(8, 4))
    plt.plot(ks, scores, 'go-')
    plt.axvline(
        x=best_k,
        color='red',
        linestyle='--',
        linewidth=1.5,
        label=f'Best at k={best_k}'
    )
    plt.xlabel('Number of Clusters (k)')
    plt.ylabel('score')
    plt.title('Silhouette method for Optimal k')
    plt.show()

    #return the best cluster because this algo auto detect the best clusters
    return best_k


def processing(data, file):
    #take the name and use only the numeric data
    player_names = data['player']
    data = data.select_dtypes(include='number')

    #scale the data to standardize the values
    scaler = StandardScaler()
    scaled = scaler.fit_transform(data)
    #apply pca to reduce the columns into lower dimension while keep the difference of the data
    component = int(input('Number of component: '))
    pca_data = pca.apply_pca(scaled, component)

    #find the best clusters number
    K = 0
    temp = input('elbow or silhouette: ')
    if temp.lower().strip() == 'elbow' or temp.lower().strip() == '1':
        K = elbow(pca_data)
    elif temp.lower().strip() == 'silhouette' or temp.lower().strip() == '2':
        K = silhouette(pca_data)
    else:
        while True:
            temp = input('try again: ')

            if temp.lower().strip() == 'elbow' or temp.lower().strip() == '1':
                K = elbow(pca_data)
                break
            elif temp.lower().strip() == 'silhouette' or temp.lower().strip() == '2':
                K = silhouette(pca_data)
                break
            else:
                continue

    #use that best clusters number to separate the dataset
    kmeans = KMeans(n_clusters=K, random_state=42, n_init=10)
    data['cluster'] = kmeans.fit_predict(pca_data)
    data['player'] = player_names.values

    #plot the data to visualize it
    if component == 2:
        pca.plot_2d(pca_data, data['cluster'], title=f'{file} player clusters')
    else:
        pca.plot_3d(pca_data, data['cluster'], title=f'{file} player clusters')

    #sort the data base on the cluster and then the player name
    data = data.sort_values(by=['cluster', 'player'], ascending=[True, True])
    data.to_csv(f'{file}_clusters.csv', index=False)

def main():
    #take the data after process
    gk, outfield = process()

    #find the number of clusters
    processing(gk, 'gk')
    processing(outfield, 'outfield')


if __name__ == '__main__':
    main()
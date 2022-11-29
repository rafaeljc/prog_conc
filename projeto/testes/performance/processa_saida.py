import numpy as np
import pandas as pd

diretorios = [
    "n10",
    "n50",
    "n250",
    "n500",
    "n1000",
    "n2000",
]

lista_testes = [
    "seq",
    "2",
    "3",
    "4",
    "5",
]

for dir in diretorios:
    lista_df = []
    for teste in lista_testes:
        with open(f"{dir}/out_{teste}.txt", 'r') as file:
            algoritmo = []
            total = []
            i = 1
            for line in file:
                if (i == 5):
                    algoritmo.append(float(line))
                if (i == 6):
                    total.append(float(line))
                    i = 1
                    continue
                i += 1
            df = pd.DataFrame(list(zip(algoritmo, total)), columns=[f"{teste}_algoritmo", f"{teste}_total"])
            df[f"{teste}_outros"] = df[f"{teste}_total"] - df[f"{teste}_algoritmo"]
            lista_df.append(df)
    df = pd.concat(lista_df, axis=1)
    df.to_csv(f"{dir}.csv", float_format='%.8f', index=False)

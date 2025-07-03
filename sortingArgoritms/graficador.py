import pandas as pd
import matplotlib.pyplot as plt

# Cargar el archivo CSV
df = pd.read_csv("resultados.csv")

# Crear la gráfica
plt.figure(figsize=(12, 6))
plt.plot(df["N"], df["BubbleSort"], label="Bubble Sort", marker='o')
plt.plot(df["N"], df["InsertionSort"], label="Insertion Sort", marker='o')
plt.plot(df["N"], df["SelectionSort"], label="Selection Sort", marker='o')
plt.plot(df["N"], df["QuickSort"], label="Quick Sort", marker='o')
plt.plot(df["N"], df["MergeSort"], label="Merge Sort", marker='o')

plt.xlabel("Tamaño del arreglo (N)")
plt.ylabel("Tiempo de ejecución (ms)")
plt.title("Comparación de algoritmos de ordenamiento")
plt.legend()
plt.grid(True)
plt.tight_layout()

# Guardar en archivo PNG en el mismo directorio
plt.savefig("grafica_algoritmos.png")
print("✅ Gráfica guardada como 'grafica_algoritmos.png'")

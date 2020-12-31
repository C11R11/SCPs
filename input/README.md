# Remover espacios extras al final de cada archivo

```
sed -i 's/\s*$//' scp41.txt
```

All the data input comes from the [the site](http://people.brunel.ac.uk/~mastjjb/jeb/orlib/scpinfo.html)

# Cómo se lee el archivo (scp410txt)

Breve explicación para leer el archivo. La versión de hoja de cálculo también realiza el análisis del mismo archivo

## Primera linea

Número de filas, Numero columnas (200, 1000)

## Línea 2 a 85 del archivo

Los costos para cada columna (son 1000 columnas). Cada línea del archivo tiene 12 valores de costos, y la última de 4. Se puede recorrer valor por valor hasta llegar a 1000

## Límneas 86 al final del archivo

Covertura de cada columna para cada fila. Se indica la cantidad de columnas que cubre, seguido por los índices de las columnas que se cubren por la fila

Lista de columnas que cubren la fila 

### Ejemplo: Línea 86, 87, 88 del archivo

El número de la línea 86 indica que la fila 1 la cubre 19 columnas.
Las líneas 87 y 88 del archivo contienen los 19 índices de cada columna cubierta (las columnas se comienzan a contar desde el número 1)

## Cálculo de valores

Si utilizo la fila 1 el costo es 1 y cubro las columnas 11 132 217 366 410 429 476 511 646 668 670 687 688 723 763 808 836 876 983 

Con esta mi función objetivo vale 1 pero no están cubiertas todas las columnas
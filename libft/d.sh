#!/bin/bash

# Lista de funciones proporcionadas
functions=("calloc"
"strdup"
"substr"
"strjoin"
"strtrim"
"itoa"
"strmapi"
"split")

# Crear archivos para cada función
for func in "${functions[@]}"; do
  filename="ft_${func}.c"
  touch "$filename"
  echo "Created: $filename"
done

echo "All files created successfully!"
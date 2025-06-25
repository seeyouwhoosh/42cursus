#!/bin/bash

# Lista de funciones proporcionadas
functions=("putchar_fd"
 "putstr_fd"
 "putendl_fd"
 "putnbr_fd")

# Crear archivos para cada función
for func in "${functions[@]}"; do
  filename="ft_${func}.c"
  touch "$filename"
  echo "Created: $filename"
done

echo "All files created successfully!"
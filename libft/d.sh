#!/bin/bash

# Lista de funciones proporcionadas
functions=(
  "isalpha" "isdigit" "isalnum" "isascii" "isprint"
  "strlen" "memset" "bzero" "memcpy" "memmove" "strlcpy" "strlcat"
  "toupper" "tolower" "strchr" "strrchr" "strncmp"
  "memchr" "memcmp" "strnstr" "atoi"
)

# Crear archivos para cada función
for func in "${functions[@]}"; do
  filename="ft_${func}.c"
  touch "$filename"
  echo "Created: $filename"
done

echo "All files created successfully!"
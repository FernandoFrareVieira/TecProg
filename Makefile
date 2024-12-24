# Diretório de destino para os arquivos .o
OBJ_DIR = obj

# Diretórios de SFML
SFML_INCLUDE_DIR = /usr/include/SFML
SFML_LIB_DIR = /usr/lib/x86_64-linux-gnu

# Lista de todos os arquivos .cpp no diretório src
CPP_FILES := $(wildcard src/*.cpp)

# Lista de arquivos .o gerados a partir dos arquivos .cpp
OBJ_FILES := $(patsubst src/%.cpp,$(OBJ_DIR)/%.o,$(CPP_FILES))

# Nome do executável
TARGET = main

# Flags de compilação
CXX = g++
CXXFLAGS = -I$(SFML_INCLUDE_DIR) -Iinclude
LDFLAGS = -L$(SFML_LIB_DIR) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lstdc++

# Regra padrão: compilar e linkar
all: $(TARGET)

# Regras para criar o executável
$(TARGET): $(OBJ_FILES)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Regra para criar o diretório de objetos e compilar os arquivos .cpp
$(OBJ_DIR)/%.o: src/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Criar o diretório de objetos, se não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Limpar os arquivos gerados
clean:
	rm -rf $(OBJ_DIR)
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean







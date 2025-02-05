# Diretório de destino para os arquivos .o
OBJ_DIR = obj

# Lista de todos os arquivos .cpp no diretório src
CPP_FILES := $(wildcard src/*.cpp)

# Lista de arquivos .o gerados a partir dos arquivos .cpp
OBJ_FILES := $(patsubst src/%.cpp,$(OBJ_DIR)/%.o,$(CPP_FILES))

# Compilador e flags
CXX = g++
CXXFLAGS = -c -Iinclude -ISFML/include

# Linker flags
LDFLAGS = -LSFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lsfml-audio

# Regra para criar o diretório de objetos, se não existir
$(OBJ_DIR):
	mkdir $(OBJ_DIR)

# Regra para compilar apenas os arquivos modificados
$(OBJ_DIR)/%.o: src/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

# Regra padrão para construir o executável
all: compile link

compile: $(OBJ_FILES)

link:
	$(CXX) -o main $(OBJ_FILES) $(LDFLAGS)

# Limpar apenas os arquivos .o e o executável
clean:
	del /Q $(OBJ_DIR)\*.o
	del main

# 👾 Pacman - ![Linguagem C](https://img.shields.io/badge/feito%20em-C-blue.svg)

Um protótipo funcional do clássico **Pac-Man**, desenvolvido em linguagem C e executado no terminal.  
Este projeto tem como objetivo praticar **manipulação de arquivos**, **alocação dinâmica de memória**, **estruturas e modularização**, e **controle de personagem com entrada do usuário**.  

> 💡 Projeto em desenvolvimento — novas funcionalidades podem ser adicionadas e/ou sugeridas!

---

## 🚀 Como Rodar

1. **Clone o repositório:**
```bash
git clone https://github.com/Guiliff/Pacman-Game.git
cd Pacman-Game
```

2. **Compile o código** com o GCC no terminal:
```bash
gcc pacman_game.c map.c -o pacman_game.out
./pacman_game.out
```

<div align="center">
  <img src="https://github.com/Guiliff/Pacman-Game/blob/main/assets/gccpacman.gif?raw=true" alt="Compilando o jogo" />
</div>


## 🎮 Como Jogar

Após compilar e executar o jogo, o personagem `@` (Pac-Man) será exibido no mapa carregado do arquivo `map_1.txt`.

Você controla o Pac-Man através do teclado, usando os seguintes comandos:

- `W` → cima  
- `A` → esquerda  
- `S` → baixo  
- `D` → direita
- `B` → usar pílula (explosão nas 4 direções)

Símbolos do jogo:

- `@` → Pacman (herói)
- `#` → Fantasma
- `+` → Pílula

📄 O mapa é lido dinamicamente, então você pode personalizá-lo livremente no arquivo map_1.txt.


<div align="center">
  <img src="https://github.com/Guiliff/Pacman-Game/blob/main/assets/testpacman.gif?raw=true" alt="Compilando o jogo" />
</div>

## 🛠 Requisitos
- Compilador C (como o GCC) via terminal, ou
- IDE com suporte à linguagem C, como:
  - Visual Studio Code (com a extensão C/C++)
  - Code::Blocks
  - Dev-C++


.

Sinta-se à vontade para explorar, sugerir melhorias ou contribuir com o projeto.
Divirta-se.

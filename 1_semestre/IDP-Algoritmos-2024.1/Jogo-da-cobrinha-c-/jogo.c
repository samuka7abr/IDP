#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>

#define WIDTH 20
#define HEIGHT 20
#define NAME_LENGTH 50

int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum Direction dir;
char playerName[NAME_LENGTH];

void Setup() {
    dir = RIGHT; // Define uma direção inicial
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;
}

void Draw() {
    // system("clear"); // Limpa a tela do console

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0)
                printf("#");
            if (i == y && j == x)
                printf("✺");
            else if (i == fruitY && j == fruitX)
                printf("⍟"); // Alterado para asterisco
            else {
                int print = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o");
                        print = 1;
                    }
                }
                if (!print)
                    printf(" ");
            }

            if (j == WIDTH - 1)
                printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    printf("Score: %d\n", score);
}

void Input() {
    struct termios old_tio, new_tio;
    unsigned char c;

    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);

    c = getchar();

    switch (c) {
    case 'a':
        if (dir != RIGHT) dir = LEFT;
        break;
    case 'd':
        if (dir != LEFT) dir = RIGHT;
        break;
    case 'w':
        if (dir != DOWN) dir = UP;
        break;
    case 's':
        if (dir != UP) dir = DOWN;
        break;
    case 'x':
        dir = STOP;
        break;
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
}

void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (x >= WIDTH) x = 0; else if (x < 0) x = WIDTH - 1;
    if (y >= HEIGHT) y = 0; else if (y < 0) y = HEIGHT - 1;

    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            dir = STOP; // Fim de jogo
        }
    }

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        nTail++;
    }
}

void SaveScore(int score, char* name) {
    FILE *file = fopen("scores.txt", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo de scores.\n");
        return;
    }
    fprintf(file, "%s %d\n", name, score);
    fclose(file);
}

void DisplayHighScores() {
    FILE *file = fopen("scores.txt", "r");
    if (file == NULL) {
        printf("Nenhum score registrado ainda.\n");
        return;
    }
    char name[NAME_LENGTH];
    int score;
    int scores[100];
    char names[100][NAME_LENGTH];
    int count = 0;
    while (fscanf(file, "%s %d", names[count], &scores[count]) != EOF && count < 100) {
        count++;
    }
    fclose(file);

    // Ordenar os scores em ordem decrescente
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (scores[i] < scores[j]) {
                int temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
                char tempName[NAME_LENGTH];
                strcpy(tempName, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], tempName);
            }
        }
    }

    printf("Top Scores:\n");
    for (int i = 0; i < count && i < 10; i++) {
        printf("%d. %s %d\n", i + 1, names[i], scores[i]);
    }
}

int main() {
    srand(time(0));
    DisplayHighScores(); // Exibir os scores antes de iniciar o jogo
    printf("Digite seu nome: ");
    fgets(playerName, NAME_LENGTH, stdin);
    // Remove o caractere de nova linha, se houver
    size_t len = strlen(playerName);
    if (len > 0 && playerName[len - 1] == '\n') {
        playerName[len - 1] = '\0';
    }
    printf("Pressione enter para iniciar o jogo...\n");
    getchar(); // Espera uma tecla ser pressionada para iniciar
    Setup();
    while (dir != STOP) {
        Draw();
        Input();
        Logic();
        usleep(100000); // Controla a velocidade da cobrinha
    }
    printf("Game Over\n");
    SaveScore(score, playerName); // Salvar o score com o nome do jogador após o jogo terminar
    printf("Seu score foi salvo!\n");
    return 0;
}


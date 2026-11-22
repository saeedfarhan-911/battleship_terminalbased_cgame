#include <stdio.h>  
#include <ctype.h> 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <sys/time.h>

#define BLUE 1
#define RED 4
#define YELLOW 14
#define WHITE 7

int arr_location[2][10][10];
int arr2_red[10][10];
int arr2_blu[10][10];
int arr_ship_details[2][5][3];
int arr_ship_details_red[5][3];
int arr_ship_details_blu[5][3];

// --- CONSOLE IN-PLACE HELPERS ---//pop
void clear_screen() {//pop
    system("cls");//pop
}//pop

void reset_cursor() {//pop
    COORD coord = {0, 0};//pop
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}//pop


void save_results(int winner) { 
    FILE *file ;  
    file = fopen("match history.txt", "a"); 
    if ( file == NULL) { 
        printf(" error in opening the file \n"); 
        return;  

    }  
    else {  
        fprintf(file,"Your Battle Records\n"); 
        if(winner==0) { 
            fprintf(file,"The Winner Was the player\n"); 
        } else if( winner==1) { 
            fprintf(file,"The winner was the computer\n");
        }
    } 
    fclose(file);
    //stores the games results in a file called match history
 }
void getcord(int *row, int *col) { 
    printf(" please enter your row for e.g. (B)\n");  
    char inputr;  
    int inputc;
    int lettervalid; 
    int numbervalid;
    scanf(" %c", &inputr);
    inputr = toupper(inputr); 
    if (inputr >= 'A' && inputr <= 'J') { 
        lettervalid = 0;
    } else { 
        do { 
            printf(" please enter  a correct row \n");
            scanf(" %c", &inputr); 
            inputr = toupper(inputr);
        } while (inputr < 'A' || inputr > 'J');
    }
    printf(" please enter your column for e.g. (4)\n");
    scanf("%d", &inputc);  
    if (inputc >= 1 && inputc <= 10) {  
        numbervalid = 0; 
    } else { 
        do { 
            printf(" please enter a correct column ");  
            scanf("%d", &inputc); 
        } while (inputc < 1 || inputc > 10);
    }
    *row = inputr - 'A'; 
    *col = inputc - 1; 
} 

int getdir() {  
    int inputd; 
    printf(" please enter your direction { 0=Right,1=Down,2=Left,3=Up}\n");  
    scanf("%d", &inputd);  
    while (inputd < 0 || inputd > 3) { 
        printf(" please enter a valid direction \n"); 
        scanf("%d", &inputd); 
    }  
    return inputd;
}    
 
void displayplayerboard(int dpbarr[2][10][10]) {  
    int i; 
    int j;  
    printf("    1  2  3  4  5  6  7  8  9  10\n");
    for (i = 0; i < 10; i++) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        printf("%c  ", 'A' + i);
        for (j = 0; j < 10; j++) {   
            if (dpbarr[0][i][j] == 0) {  
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
                printf(" . ");
            } else if (dpbarr[0][i][j] >= 1 && dpbarr[0][i][j] <= 5) { 
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                printf(" S "); 
            } else if (dpbarr[0][i][j] == 99) {  
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                printf(" X "); 
            } else if (dpbarr[0][i][j] == -1) {  
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
                printf(" O ");
            }
        } 
        printf("\n");
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
} 

//DisplayCPUboard : 
void displaycpuboard(int dcbarr[2][10][10]) { 
    int i; 
    int j; 
    printf("   1  2  3  4  5  6  7  8  9  10\n"); 
    for (i = 0; i < 10; i++) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
        printf("%c ", 'A' + i);
        for (j = 0; j < 10; j++) { 
            if (dcbarr[1][i][j] == 0) { 
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
                printf(" . ");
            } if (dcbarr[1][i][j] == -1) {  
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), YELLOW);
                printf(" O ");
            } if (dcbarr[1][i][j] == 99) { 
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
                printf(" X ");
            } if (dcbarr[1][i][j] >= 1 && dcbarr[1][i][j] <= 5) {  
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
                printf(" . ");
            }
        } 
        printf("\n");
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}

unsigned get_microseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000) + tv.tv_usec;
}

void rc(int *rc_row, int *rc_col) {
    srand(get_microseconds());
    *rc_row = rand() % 10;
   
    *rc_col = rand() % 10;
   
}

void random_cordinate(int *rac_row, int *rac_col) {
    do { 
        rc(rac_row, rac_col);
    } while (arr_location[0][*rac_row][*rac_col] == 99 || arr_location[0][*rac_row][*rac_col] == -1);
}



void board(int barr[2][10][10]) {
    int i, j, k;
    for (k = 0; k < 2; k++) {
        for (i = 0; i <= 9; i++) {
            for (j = 0; j <= 9; j++) {
                barr[k][i][j] = 0;
            }
        }
    }
}

void sae(int saarr[5][3]) {
    for (int j = 2; j <= 5; j++) {
        saarr[j - 2][0] = (j) * 10;
        saarr[j - 2][1] = j;
    }
}

void s3d_2d_sa(int s3mz, int s3mzarr[2][5][3], int s2mzarr[5][3]) {
    int i, j;
    for (i = 0; i <= 4; i++) {
        for (j = 0; j <= 2; j++) {
            s2mzarr[i][j] = s3mzarr[s3mz][i][j];
        }
    }
}

void s3d_2d_ma(int s3z, int s3zarr[2][10][10], int s2arr[10][10]) {
    int i, j;
    for (i = 0; i <= 9; i++) {
        for (j = 0; j <= 9; j++) {
            s2arr[i][j] = s3zarr[s3z][i][j];      
        }
    }
}

int vd(int vdrow, int vdcol, int vdarr[10][10]) {
    if (vdarr[vdrow][vdcol] == 0) {
        return 1111;
    } else {
        return 77;
    }
}

int sp(int sprow, int spcol, int spdir, int splen, int sparr[10][10]) {
    int spi;
    switch (spdir) {
        case 0:
            if ((spcol + splen - 1 >= 10))
                return 444;
            for (spi = 0; spi < splen; spi++) {
                if (vd(sprow, spcol + spi, sparr) == 77)
                    return 444;
            }
            for (spi = 0; spi < splen; spi++) {
                sparr[sprow][spcol + spi] = splen;
            }
            break;

        case 1:
            if (sprow + splen - 1 >= 10)
                return 444;
            for (spi = 0; spi < splen; spi++) {
                if (vd(sprow + spi, spcol, sparr) == 77)
                    return 444;
            }
            for (spi = 0; spi < splen; spi++) {
                sparr[sprow + spi][spcol] = splen;
            }
            break;

        case 2:
            if (spcol - (splen - 1) < 0)
                return 444;
            for (spi = 0; spi < splen; spi++) {
                if (vd(sprow, spcol - spi, sparr) == 77)
                    return 444;
            }
            for (spi = 0; spi < splen; spi++) {
                sparr[sprow][spcol - spi] = splen;
            }
            break;

        case 3:
            if (sprow - (splen - 1) < 0)
                return 444;
            for (spi = 0; spi < splen; spi++) {
                if (vd(sprow - spi, spcol, sparr) == 77)
                    return 444;
            }
            for (spi = 0; spi < splen; spi++) {
                sparr[sprow - spi][spcol] = splen;
            }
            break;

        default:
            return 444;
    }
    return 1010;
}

void spir(int spiarr[10][10]) {
    int i, j;
    printf("\n\n");
    for (i = 0; i <= 9; i++) {
        for (j = 0; j <= 9; j++) {
            printf("%d\t", spiarr[i][j]);
        }
        printf("\n");
    }
}

void s2d_3d_ma(int s2z, int s3zarr[2][10][10], int s2arr[10][10]);

void user_da(int uarr[10][10], int usae[5][3]) {
    int urows, ucols;
    int dir_s;
    int dir_sps;
    printf("\n Commander! place your Aircraft Carrier of length 5  \n");
    do {
        getcord(&urows, &ucols);
        dir_s = getdir();
        dir_sps = sp(urows, ucols, dir_s, 5, uarr);
        if (dir_sps == 444) {
            printf("\nEror\n");
        }
    } while (dir_sps == 444);
    s2d_3d_ma(0, arr_location, uarr);
    displayplayerboard(arr_location);

    int urowac, ucolac;
    int dir_ac;
    int dir_spac;
    printf("\n Commander! place your Cruiser of length 4 \n");
    do {
        getcord(&urowac, &ucolac);
        dir_ac = getdir();
        dir_spac = sp(urowac, ucolac, dir_ac, 4, uarr);
        if (dir_spac == 444) {
            printf("\nEror\n");
        }
    } while (dir_spac == 444);
    s2d_3d_ma(0, arr_location, uarr);
    displayplayerboard(arr_location);

    int urowd, ucold;
    int dir_d;
    int dir_spd;
    printf("\n Commander! place your Destroyer of length 3 \n");
    do {
        getcord(&urowd, &ucold);
        dir_d = getdir();
        dir_spd = sp(urowd, ucold, dir_d, 3, uarr);
        if (dir_spd == 444) {
            printf("\nEror...\n");
        }
    } while (dir_spd == 444);
    s2d_3d_ma(0, arr_location, uarr);
    displayplayerboard(arr_location);

    int urowf, ucolf;
    int dir_f;
    int dir_spf;
    printf("\n Commander! place your frigate of length 2 \n");
    do {
        getcord(&urowf, &ucolf);
        dir_f = getdir();
        dir_spf = sp(urowf, ucolf, dir_f, 2, uarr);
        if (dir_spf == 444) {
            printf("\nEror\n");
        }
    } while (dir_spf == 444);
    s2d_3d_ma(0, arr_location, uarr);
    displayplayerboard(arr_location);

    sae(usae);
    usae[0][2] = dir_f;
    usae[1][2] = dir_d;
    usae[2][2] = dir_ac;
    usae[3][2] = dir_s;
}

int dir_ai() {
    int d_ai;
    srand(get_microseconds());
    ;
    d_ai = rand() % 4;
    return d_ai;
}
    
int sp_ai(int sairow, int saicol, int sadir, int sa_len, int saiarr[10][10]) {
    int spi;
    switch (sadir) {
        case 0:
            if ((saicol + sa_len - 1 >= 10))
                return 444;
            for (spi = 0; spi < sa_len; spi++) {
                if (vd(sairow, saicol + spi, saiarr) == 77)
                    return 444;
            }
            for (spi = 0; spi < sa_len; spi++) {
                saiarr[sairow][saicol + spi] = sa_len;
            }
            break;

        case 1:
            if (sairow + sa_len - 1 >= 10)
                return 444;
            for (spi = 0; spi < sa_len; spi++) {
                if (vd(sairow + spi, saicol, saiarr) == 77)
return 444;
}
for (spi = 0; spi < sa_len; spi++) {
saiarr[sairow + spi][saicol] = sa_len;
}
break;
case 2:
if (saicol - (sa_len - 1) < 0)
return 444;
for (spi = 0; spi < sa_len; spi++) {
if (vd(sairow, saicol - spi, saiarr) == 77)
return 444;
}
for (spi = 0; spi < sa_len; spi++) {
saiarr[sairow][saicol - spi] = sa_len;
}
break;
case 3:
if (sairow - (sa_len - 1) < 0)
return 444;
for (spi = 0; spi < sa_len; spi++) {
if (vd(sairow - spi, saicol, saiarr) == 77)
return 444;
}
for (spi = 0; spi < sa_len; spi++) {
saiarr[sairow - spi][saicol] = sa_len;
}
break;
default:
return 444;
}
return 1010;
}
void ai_da(int spafarr[10][10], int aisae[5][3]) {
int sp_afsrow, sp_afscol, sp_aifsdir, sp_afs_spai;
do {
sp_aifsdir = dir_ai();
rc(&sp_afsrow, &sp_afscol);
sp_afs_spai = sp_ai(sp_afsrow, sp_afscol, sp_aifsdir, 5, spafarr);
} while (sp_afs_spai == 444);
int sp_afarow, sp_afacol, sp_afadir, sp_afa_spai;
do {
sp_afadir = dir_ai();
rc(&sp_afarow, &sp_afacol);
sp_afa_spai = sp_ai(sp_afarow, sp_afacol, sp_afadir, 4, spafarr);
} while (sp_afa_spai == 444);
int sp_afdrow, sp_afdcol, sp_afddir, sp_afd_spai;
do {
sp_afddir = dir_ai();
rc(&sp_afdrow, &sp_afdcol);
sp_afd_spai = sp_ai(sp_afdrow, sp_afdcol, sp_afddir, 3, spafarr);
} while (sp_afd_spai == 444);
int sp_affrow, sp_affcol, sp_affdir, sa_aff_spai;
do {
sp_affdir = dir_ai();
rc(&sp_affrow, &sp_affcol);
sa_aff_spai = sp_ai(sp_affrow, sp_affcol, sp_affdir, 2, spafarr);
} while (sa_aff_spai == 444);
sae(aisae);
aisae[0][2] = sp_affdir;
aisae[1][2] = sp_afddir;
aisae[2][2] = sp_afadir;
aisae[3][2] = sp_aifsdir;
}
void s2d_3d_sa(int s2mz, int s3mzarr[2][5][3], int s2mzarr[5][3]) {
int i, j;
for (i = 0; i <= 4; i++) {
for (j = 0; j <= 2; j++) {
s3mzarr[s2mz][i][j] = s2mzarr[i][j];
}
}
}
void s2d_3d_ma(int s2z, int s3zarr[2][10][10], int s2arr[10][10]) {
int i, j;
for (i = 0; i <= 9; i++) {
for (j = 0; j <= 9; j++) {
s3zarr[s2z][i][j] = s2arr[i][j];
}
}
}

int ship_id;
int ship_sunk = 0;
int ship_size = 1;
int PLAYER_ID = 0;
bool turn_change_flag, game_end = false;
int rows;
int columns;
// --- FUNCTION PROTOTYPES ---
void getcord(int *r, int *c);//pop
void random_cordinate(int *r, int *c);
void getcord_mechanism(int PLAYER_ID);
void hit_input_mechanism(int player_no);
bool check_allship_sunk(int player_no);
int winner_declare(int PLAYER_ID);
void turn_change();
void manipulate_arrlocation();
// Updates both boards in-place and prints the outcome statement on the spot
void render_live_boards(const char *turn_title, const char *statement) {//pop
reset_cursor();//pop
printf("%s                                        \n", turn_title);
printf("--- ENEMY WATERS ---\n");//pop
displaycpuboard(arr_location);//pop
printf("\n--- YOUR FLEET ---\n");//pop
displayplayerboard(arr_location);//pop
printf("\n-------------------------------------------------------------------\n");
printf("OUTCOME: %-60s\n", statement);//pop
printf("-------------------------------------------------------------------\n");
}//pop
void getcord_mechanism(int PLAYER_ID) {
switch (PLAYER_ID) {
case 0: getcord(&rows, &columns);
break;
case 1: random_cordinate(&rows, &columns);
break;
}
}
void hit_input_mechanism(int player_no) {
bool is_input = true;
getcord_mechanism(PLAYER_ID);
while (is_input == true) {
if (arr_location[player_no][rows][columns] == 0 || (arr_location[player_no][rows][columns] >= 2 && arr_location[player_no][rows][columns] <= 5)) {
is_input = false;
} else {
if (PLAYER_ID == 0) {
printf("Already targeted! Enter another coordinate:\n");
}
getcord_mechanism(PLAYER_ID);
}
}
}
void manipulate_arrlocation() {//pop somewhere idk
turn_change_flag = false;
int player_no = !PLAYER_ID;
char outcome_msg[120] = "Awaiting coordinates...";
do {
if (PLAYER_ID == 0) {
render_live_boards("-------------Your turn----------------", outcome_msg);
} else {
render_live_boards("**----------------enemy turn-----------------", "Enemy is aiming...");
Sleep(3000);
}
hit_input_mechanism(player_no);
if (arr_location[player_no][rows][columns] == 0) {
arr_location[player_no][rows][columns] = -1;
turn_change_flag = true;
switch (PLAYER_ID) {
case 0:
sprintf(outcome_msg, "Commander you missed the target. Recalibrate! | turn change");
break;
case 1:
sprintf(outcome_msg, "Enemy missed the target | turn change");
break;
}
} else if (arr_location[player_no][rows][columns] > 1 && arr_location[player_no][rows][columns] <= 5) {
ship_id = arr_location[player_no][rows][columns];
arr_location[player_no][rows][columns] = 99;
arr_ship_details[player_no][ship_id - 2][ship_size] -= 1;
if (arr_ship_details[player_no][ship_id - 2][ship_size] == 0) {
ship_sunk++;
switch (PLAYER_ID) {
case 0:
sprintf(outcome_msg, "You sunk their ship! congrats commander | Another turn");
break;
case 1:
sprintf(outcome_msg, "Enemy sunk the ship! | Another turn");
break;
}
} else {
switch (PLAYER_ID) {
case 0:
sprintf(outcome_msg, "BULLSEYE! you hit the enemy ship | Another turn");
break;
case 1:
sprintf(outcome_msg, "Enemy hit the ship | Another turn");
break;
}
}
}
// Instantly update the array on screen at the exact same spot with the outcome statement
if (PLAYER_ID == 0) {
render_live_boards("-------------Your turn----------------", outcome_msg);
} else {
render_live_boards("**----------------enemy turn-----------------", outcome_msg);
}
Sleep(2500);
clear_screen();
} while (!check_allship_sunk(player_no) && turn_change_flag == false);
if (check_allship_sunk(player_no)) {
game_end = true;
render_live_boards("*************** GAME OVER ***************", outcome_msg);
winner_declare(PLAYER_ID);
}
}
bool check_allship_sunk(int player_no) {
int flag = true;
for (int i = 0; i < 4; i++) {
if (arr_ship_details[player_no][i][ship_size] == 0) {
} else {
flag = false;
}
}//pop
return flag;
}
int winner_declare(int PLAYER_ID) {
int winner;
switch (PLAYER_ID) {
case 0:
printf("\n---------  Victory is Ours!  ---------\n");
winner = 0;
break;
case 1:
printf("\n---------  The enemy has won...   ---------\n");
winner = 1;
break;
}  
save_results(winner);
return winner;
}
void turn_change() {
if (turn_change_flag == true) {
switch (PLAYER_ID) {
case 0: PLAYER_ID = 1;
break;
case 1: PLAYER_ID = 0;
break;
}
}
}
int main() {
board(arr_location); // places water everywhere
s3d_2d_ma(0, arr_location, arr2_red);
s3d_2d_sa(0, arr_ship_details, arr_ship_details_red);
user_da(arr2_red, arr_ship_details_red);
s3d_2d_ma(1, arr_location, arr2_blu);
s3d_2d_sa(1, arr_ship_details, arr_ship_details_blu);
ai_da(arr2_blu, arr_ship_details_blu);
// stitching back
s2d_3d_ma(0, arr_location, arr2_red);
s2d_3d_ma(1, arr_location, arr2_blu);
s2d_3d_sa(0, arr_ship_details, arr_ship_details_red);
s2d_3d_sa(1, arr_ship_details, arr_ship_details_blu);
clear_screen(); // Clear setup text once before battle starts
while (!game_end) {//pop
manipulate_arrlocation();
if (!game_end) {
turn_change();
}
}
return 0;
}
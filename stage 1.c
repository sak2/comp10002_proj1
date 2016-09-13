/*
STAGE 1 OUTPUT LEVEL COMPLETE!
STAGE 1 COMMENTING REMAINING...
STAGE 1 CODE READABILTY REMAINING...
STAGE 1 CODE OPTIMISATION REMAINING...
*/
#include <stdio.h>
#include <stdlib.h>

/* Defining maximum number of rows, columns in the table and characters in a
cell */
#define ROW 1000
#define COL 30
#define CEL 50

/* Defining how to interpret the function ctype */
#define COLEND 1
#define ROWEND 2

int
mygetchar();
void
tsvreader();
/*void
printtable()*/

int main(int argc, char *argv[]) {
	int rows = 0;
	int cols = 0;
	int i = 0;
	char table[ROW][COL][CEL];
	tsvreader(table, &rows, &cols);
	printf("Stage 1 Output\n");
	printf("input tsv data has %d rows and %d columns\n", rows, cols);
	printf("row %d is:\n", rows);
	for (i=0; i<cols; i++) {
		printf("%4d: %-11s %s\n", (i+1), table[0][i], table[rows][i]);
	}

	/*printtable();*/
	return 0;
}

int mygetchar() {
	int c = 0;
	while ((c=getchar())=='\r') {
	}
	return c;
}

int ctype(int c) {
	if (c == '\t') {
		return COLEND;
	}
	if (c == '\n') {
		return ROWEND;
	}

	return 0; /* ??? */
}

void tsvreader(char table[ROW][COL][CEL],int *rows,int *cols) {
	/* Initialising variables */


	int i, j, k;
	int colbreakcount = 0;
	int EOFtrue, rowbreak = 0;
	int c;

for (i=0; i<ROW; i++) {
	if (EOFtrue == 1) {
		//printf("\nEOFtrue\n");
		break;
	}
		for (j=0; j<COL; j++) {
			if (rowbreak == 1) {
				rowbreak = 0;
				break;
			}
			if (EOFtrue == 1) {
				break;
			}

			for (k=0; k<CEL; k++) {
				c = mygetchar();
				if (c == EOF) {
					EOFtrue = 1;
					break;
				}
				if (ctype(c) == ROWEND) {
					*rows += 1;
					colbreakcount += 1;
					rowbreak = 1;
					break;
				}

				if (ctype(c) == COLEND) {
					colbreakcount += 1;
					break;
				}

				//printf("%c", c);
				table[i][j][k] += (char)c;
			}
		}
	}
	*cols = (colbreakcount / *rows);
	*rows = *rows - 1;

	}

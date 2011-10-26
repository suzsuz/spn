/* Header-Datei für einfache Substitution-Permutation-Networks
(nach D. R. Stinson: Cryptography, Theory and Practice)
*/

#define NR 4    // Anzahl der Runden

typedef unsigned char S_BOX[16];
typedef unsigned char PERM[16]; 
/* Die Permutation der Bits eines C_BLOCKS 
 wird durch die Positionen in diesem     
 array beschrieben.                     
 D.h. Bit n --> Bit PERM[n]            
 Dabei ist die Zählung anders als im Buch von Stinson. 
 Die Positionen gehen von 0 bis 15 und 0 ist das least significant bit. */
                              
typedef unsigned long KEY;
typedef unsigned short KEY_SCHEDULE[NR+1];
typedef unsigned short C_BLOCK;
typedef enum{DECRYPT,ENCRYPT}   ENC_TYPE;
typedef struct spn {
	S_BOX sbox;
	PERM perm;
} SPN;

int schedule(KEY k, KEY_SCHEDULE ks);
/* erzeugt den key schedule ks aus dem key k*/

C_BLOCK sboxop(C_BLOCK c, S_BOX s);
/* definiert die s-box-operation auf dem Block c und gibt das Resultat zurück*/

C_BLOCK permop(C_BLOCK c, PERM p);
/* definiert die Permutation */

C_BLOCK crypt(ENC_TYPE t, KEY k, C_BLOCK c, SPN sp);
/* Programm für Ver- und Entschlüsselung. t enthält 
den Typ ENCRYPT oder DECRYPT */

void sboxinv(S_BOX s);
/* ermittelt die inverse Permutation zur S_BOX s und gibt sie in s zurück */

void perminv(PERM p);
/* ermittelt die inverse der Permutation PERM p und gibt sie in p zurück */


grammar Asm;

code
    : statement ( statement * )
    ;

statement
    : symbol ? instruction ( eol + )
    ;

symbol : ID ;

instruction
    : mem_ins
    | opr_ins
    | iot_ins
    | ctl_ins
    ;

ctl_ins
    : start
    ;

start : '.' address ;

mem_ins
    : mem_op zero ? ind ? address
    ;

mem_op
    : A N D
    | T A D
    | I S Z
    | D C A
    | J M S
    | J M P
    ;

zero : '!' ;
ind : '@' ;

address
    : Octal
    | Decimal
    ;

opr_ins
    : opr_op1 +
    | opr_op2 +
    | opr_op3 +
    ;

opr_op1
    : N O P | I A C | R A L | R T L | R A R | R T R | B S W | C M L | C M A | C I A | C L L | S T L | C L A | S T A
    ;

opr_op2
    : H L T | O S R | S K P | S N L | S Z L | S Z A | S N A | S M A | S P A | C L A
    ;

opr_op3
    : C M A | M Q A | M Q L | S W P
    ;

iot_ins
    : I O T
    | I O N | S K O N | I O F | S R Q | G T F | R T F | S G T | C A F
    ;

eol
    : ';'
    | '\n'
    | '\r' '\n'
    ;

fragment A:('a'|'A');
fragment B:('b'|'B');
fragment C:('c'|'C');
fragment D:('d'|'D');
fragment E:('e'|'E');
fragment F:('f'|'F');
fragment G:('g'|'G');
fragment H:('h'|'H');
fragment I:('i'|'I');
fragment J:('j'|'J');
fragment K:('k'|'K');
fragment L:('l'|'L');
fragment M:('m'|'M');
fragment N:('n'|'N');
fragment O:('o'|'O');
fragment P:('p'|'P');
fragment Q:('q'|'Q');
fragment R:('r'|'R');
fragment S:('s'|'S');
fragment T:('t'|'T');
fragment U:('u'|'U');
fragment V:('v'|'V');
fragment W:('w'|'W');
fragment X:('x'|'X');
fragment Y:('y'|'Y');
fragment Z:('z'|'Z');

Octal : '0' [0-7]+ ;

Decimal : '0' | [1-9] [0-9]* ;

ID  : [a-zA-Z_] [a-zA-Z0-9_]* ;

WS : [ \t]+ -> skip ;

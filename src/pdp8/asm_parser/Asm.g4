grammar Asm;

code
    : statements EOF
    ;

statements : statement + ;

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
    : mem_and
    | mem_tad
    | mem_isz
    | mem_dca
    | mem_jms
    | mem_jmp
    ;

mem_and : AND ;
mem_tad : TAD ;
mem_isz : ISZ ;
mem_dca : DCA ;
mem_jms : JMS ;
mem_jmp : JMP ;

zero : '!' ;
ind : '@' ;

address
    : Octal
    | Decimal
    ;

opr_ins
    : opr_op1
    | opr_op2
    | opr_op3
    ;

opr_op1 : opr_op1_ins + ;

opr_op1_ins
    : nop | iac | ral | rtl | rar | rtr | bsw | cml | cma | cia | cll | stl | cla | sta
    ;

nop : NOP ;
iac : IAC ;
ral : RSL ;
rtl : RTL ;
rar : RAR ;
rtr : RTR ;
bsw : BSW ;
cml : CML ;
cma : CMA ;
cia : CIA ;
cll : CLL ;
stl : STL ;
cla : CLA ;
sta : STA ;

opr_op2 : opr_op2_ins + ;

opr_op2_ins
    : hlt | osr | skp | snl | szl | sza | sna | sma | spa | cla
    ;

hlt : HLT ;
osr : OSR ;
skp : SKP ;
snl : SNL ;
szl : SZL ;
sza : SZA ;
sna : SNA ;
sma : SMA ;
spa : SPA ;

opr_op3 : opr_op3_ins +;

opr_op3_ins
    : cam | mqa | mql | swp
    ;

cam : CAM ;
mqa : MQA ;
mql : MQL ;
swp : SWP ;

iot_ins
    : iot
    | ion | skon | iof | srq | gtf | rtf | caf
    ;

iot : IOT ;
ion : ION ;
skon : SKON ;
iof : IOF ;
srq : SRQ ;
gtf : GTF ;
rtf : RTF ;
caf : CAF ;

eol
    : ';'
    | '\n'
    | '\r' '\n'
    ;


AND : [Aa][Nn][Dd] ;
TAD : [Tt][Aa][Dd] ;
ISZ : [Ii][Ss][Zz] ;
DCA : [Dd][Cc][Aa] ;
JMS : [Jj][Mm][Ss] ;
JMP : [Jj][Mm][Pp] ;

NOP : [Nn][Oo][Pp] ;
IAC : [Ii][Aa][Cc] ;
RSL : [Rr][Ss][Ll] ;
RTL : [Rr][Tt][Ll] ;
RAR : [Rr][Aa][Rr] ;
RTR : [Rr][Tt][Rr] ;
BSW : [Bb][Ss][Ww] ;
CML : [Cc][Mm][Ll] ;
CMA : [Cc][Mm][Aa] ;
CIA : [Cc][Ii][Aa] ;
CLL : [Cc][Ll][Ll] ;
STL : [Ss][Tt][Ll] ;
CLA : [Cc][Ll][Aa] ;
STA : [Ss][Tt][Aa] ;

HLT : [Hh][Ll][Tt] ;
OSR : [Oo][Ss][Rr] ;
SKP : [Ss][Kk][Pp] ;
SNL : [Ss][Nn][Ll] ;
SZL : [Ss][Zz][Ll] ;
SZA : [Ss][Zz][Aa] ;
SNA : [Ss][Nn][Aa] ;
SMA : [Ss][Mm][Aa] ;
SPA : [Ss][Pp][Aa] ;

CAM : [Cc][Aa][Mm] ;
MQA : [Mm][Qq][Aa] ;
MQL : [Mm][Qq][Ll] ;
SWP : [Ss][Ww][Pp] ;

IOT : [Ii][Oo][Tt] ;
ION : [Ii][Oo][Nn] ;
SKON : [Ss][Kk][Oo][Nn] ;
IOF : [Ii][Oo][Ff] ;
SRQ : [Ss][Rr][Qq] ;
GTF : [Gg][Tt][Ff] ;
RTF : [Rr][Tt][Ff] ;
CAF : [Cc][Aa][Ff] ;

Octal : '0' [0-7]+ ;

Decimal : '0' | [1-9] [0-9]* ;

ID  : [a-zA-Z_] [a-zA-Z0-9_]* ;

WS : [ \t]+ -> skip ;

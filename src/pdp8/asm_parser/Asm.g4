grammar Asm;

code
    : statements EOF
    ;

statements : statement + ;

statement
    : instruction
    | pragma
    ;

pragma
    : symbol ? ctl_ins (eol + )
    ;

instruction
    : symbol ? cpu_ins ( eol + )
    ;

symbol : ID ;

cpu_ins
    : mem_ins
    | opr_ins
    | iot_ins
    | def_const
    ;

ctl_ins
    : symbol ? start
    ;

start : '.' ( address | symbol );

mem_ins
    : mem_op zero ? ind ? ( address | symbol )
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
ral : RAL ;
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
    | ion | skon | iof | srq | gtf | rtf | sgt | caf | cdf | cif | cidf | rdf | rif | rib | rmf
    | dk8ea
    ;

iot : IOT ;
ion : ION ;
skon : SKON ;
iof : IOF ;
srq : SRQ ;
gtf : GTF ;
rtf : RTF ;
sgt : SGT ;
caf : CAF ;
cdf : CDF ;
cif : CIF ;
cidf : CIDF ;
rdf : RDF ;
rif : RIF ;
rib : RIB ;
rmf : RMF ;

dk8ea : CLSF | CLEI | CLDI | CLSC | CLSI | CLSM | RAND | CLSK | CLLE | CLCL;

def_const
    : dw
    ;

dw
    : DW address
    ;

eol
    : ';'
    | '\n'
    | '\r' '\n'
    ;

fragment A: [Aa];
fragment B: [Bb];
fragment C: [Cc];
fragment D: [Dd];
fragment E: [Ee];
fragment F: [Ff];
fragment G: [Gg];
fragment H: [Hh];
fragment I: [Ii];
fragment J: [Jj];
fragment K: [Kk];
fragment L: [Ll];
fragment M: [Mm];
fragment N: [Nn];
fragment O: [Oo];
fragment P: [Pp];
fragment Q: [Qq];
fragment R: [Rr];
fragment S: [Ss];
fragment T: [Tt];
fragment U: [Uu];
fragment V: [Vv];
fragment W: [Ww];
fragment X: [Xx];
fragment Y: [Yy];
fragment Z: [Zz];

DW  : D W ;

AND : A N D ;
TAD : T A D ;
ISZ : I S Z ;
DCA : D C A ;
JMS : J M S ;
JMP : J M P ;

NOP : N O P ;
IAC : I A C ;
RAL : R A L ;
RTL : R T L ;
RAR : R A R ;
RTR : R T R ;
BSW : B S W ;
CML : C M L ;
CMA : C M A ;
CIA : C I A ;
CLL : C L L ;
STL : S T L ;
CLA : C L A ;
STA : S T A ;

HLT : H L T;
OSR : O S R;
SKP : S K P;
SNL : S N L;
SZL : S Z L;
SZA : S Z A;
SNA : S N A;
SMA : S M A;
SPA : S P A;

CAM : C A M;
MQA : M Q A;
MQL : M Q L;
SWP : S W P;

IOT : I O T;
ION : I O N;
SKON : S K O N;
IOF : I O F;
SRQ : S R Q;
GTF : G T F;
RTF : R T F;
SGT : S G T;
CAF : C A F;
CDF : C D F;
CIF : C I F;
CIDF : C I D F;
RDF : R D F;
RIF : R I F;
RIB : R I B;
RMF : R M F;

CLSF : C L S F;
CLEI : C L E I;
CLDI : C L D I;
CLSC : C L S C;
CLSI : C L S I;
CLSM : C L S M;
RAND : R A N D;
CLSK : C L S K;
CLLE : C L L E;
CLCL : C L C L;

Octal : '0' [0-7]+ ;

Decimal : '0' | [1-9] [0-9]* ;

ID  : [a-zA-Z_] [a-zA-Z0-9_]* ;

WS : [ \t]+ -> skip ;

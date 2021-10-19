%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "asin.h"

#define retornar(x) {if (verbosidad) ECHO; return(x);}
%}

%option noinput
%option nounput

%option yylineno

letra           [a-zA-Z]
digito          [0-9]
delimitador     [ \t\n]
comentario      \/\/.*
entero          {digito}+
constante       {digito}+(\.{digito}+)?
identificador   {letra}({letra}|{digito}|_)*


%%

{delimitador} {if (verbosidad) ECHO ; }
{comentario}    { if (verbosidad) ECHO;    }

"struct"        { retornar(STRUCT_);         }
"read"          { retornar(READ_);         }
"print"         { retornar(PRINT_);        }
"if"            { retornar(IF_);           }
"else"          { retornar(ELSE_);         }
"elseif"        { retornar(ELSEIF_);       }
"while"         { retornar(WHILE_);        }
"do"            { retornar(DO_);           }
"int"           { retornar(INT_);          }
"bool"          { retornar(BOOL_);         }
"true"          { retornar(TRUE_);         }
"false"         { retornar(FALSE_);        }
"return"         { retornar(RETURN_);        }

"=="            { retornar(OPIGUAL_);      }
"!="            { retornar(OPNOTIGUAL_);   }
"+="            { retornar(MASIGUAL_);     }
"-="            { retornar(MENOSIGUAL_);   }
"*="            { retornar(PORIGUAL_);     }
"/="            { retornar(DIVIGUAL_);     }
"++"            { retornar(OPINCREMENTO_); }
"--"            { retornar(OPDECREMENTO_); }
"&&"            { retornar(OPAND_);        }
"||"            { retornar(OPOR_);         }
"<"             { retornar(COMPMENOR_);    }
">"             { retornar(COMPMAYOR_);    }
"<="            { retornar(COMPMENORIG_);  }
">="            { retornar(COMPMAYORIG_);  }
"="             { retornar(IGUAL_);        }
"+"             { retornar(OPSUMA_);       }
"-"             { retornar(OPRESTA_);      }
"*"             { retornar(OPMULT_);       }
"/"             { retornar(OPDIV_);        }
"%"             { retornar(OPMOD_);        }
"!"             { retornar(OPNOT_);        }
"("             { retornar(PARENTESIS1_);  }
")"             { retornar(PARENTESIS2_);  }
"{"             { retornar(LLAVE1_);       }
"}"             { retornar(LLAVE2_);       }
"["             { retornar(CORCHETE1_);    }
"]"             { retornar(CORCHETE2_);    }
","             { retornar(COMA_);         }
";"             { retornar(SEMICOLON_);    }
"."             { retornar(PUNTO_);        }

{constante}     { retornar(CTE_);          }
{identificador} { retornar(ID_);           }

. { yyerror("Caracter desconocido") ;}

%%

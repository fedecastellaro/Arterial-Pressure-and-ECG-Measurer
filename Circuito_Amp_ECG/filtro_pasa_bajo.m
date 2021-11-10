%%%%%%%%%%PROGRAMA PARA CALCULAR LOS VALORES DE LOS COMPONENTES PARA HACER
%%%%%%%%%%UN FILTRO PASA BAJO BUTTERWORTH DE ORDEN N%%%%%%%%%

%NOTA: MODIFICAR fc / K / a1 / b1 ( frecuencia de corte, ganancia del filtro, 
%constantes a y b dependiendo del orden ) respectivamente segun lo necesario.

%NOTA2: SE RECOMIENDA, UNA VEZ OBTENIDO LOS VALORES, IR RECALCULANDOLOS EN
%FUNCION DE LAS APROXIMACIONES DADAS POR LOS VALORES COMERCIALES MAS
%PROXIMOS.

%LOS VALORES A CONTINUACION REPRESENTAN LOS NECESARIOS PARA EL DISEÑO DEL
%FILTRO PASA BAJOS, CON UNA FRECUENCIA DE CORTE DE 250 HZ, GANANCIA
%UNITARIA, Y CON LOS VALORES CTES CORRESPONDIENTES AL DE UN FILTRO BUTTER
%DE 4TO ORDEN OBTENIDOS DE LA TABLA. 


clear;
clc;

K = 1;
fc= 250;
%a1= 1.847759;
a1= 0.765367; 
b1= 1;

c2= (10/fc)*1e-6
%c2 = 39e-9 ; % valor aproximado


wc = 2*pi*fc;

ac2= a1 * c2;

c1 = ( (a1^2) * c2 ) / (4 * b1 * (K+1) )
%c1 = 2.7e-9 ; % valor aproximado

R2 = (2 * (K+1)) / ((ac2 + sqrt ( (ac2^2)- (4*b1*c1*c2*(K+1)) )) * wc)

%R2 = 150000 ; % valor aproximado

R1 = R2 / K

R3 = 1 / (b1* c1 * c2 * (wc^2) * R2)

%%
%RESPUESTA EN FRECUENCIA



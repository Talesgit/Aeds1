No exercício 2, (Guia0312) não soube criar um turnAroundCornerLeft, nem soube qual recurso chamar para fazer curva fechada á esquerda.
Tentei algo como na turnAround que fiz:
void turnAround( )
{
    if ( facingEast( ) )
    {
        turnLeft();
        turnLeft();
        move();
    }else if ( facingWest( ) )
    {
        turnRight();
        turnRight();
        move();
    }
    


}
(Também teve o else if do facingSouth e North), mas nem entendi ao certo o que seria "acompanhar uma parede interna".

No caso abaixo, eu precisava de que o if leftIsClear fosse executado 2 vezes, mas também precisava do else if rightIsClear
void run()
{
    if (leftIsClear())
    {
     turnLeft();
     moveN(6);
    }else if (rightIsClear())
    {
    turnRight();
    moveN(6);
    faceSouth();
    }
Não soube como fazer, então as viradas a esquerda e direita foram feitas manualmente com "turnLeft" e right.

-No EX 4,O que quer dizer com "- poderá ser indicado em um mapa o percurso efetuado,
se as posições percorridas forem marcadas ou
se forem guardadas em arquivo e, posteriormente,
mostradas ao final como o roteiro percorrido."? 
E o que quis dizer na DICA do exercício 4?

No exercício 5, não consegui utilizar o if para colocar e pegar o marcador, pois não soube fazer o robò "esperar" e continuar a ação até o proximo chehar para pegar o marcador,
ao chagar para pegar o marcador ele entrava em shutdown. Mas todos os passos foram feitos porém sem o método if.

NO extra 1, não soube o que era e,
No extra 2, por não ter funcionado com o método if, não foi possível fazer a troca de marcadores, nem manualmente, e no final, deu um erro de can´t move no primeiro robô, para qualquer direção que ele apontasse. 

                   
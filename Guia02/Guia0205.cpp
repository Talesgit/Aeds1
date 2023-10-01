/*
Guia_0205 - v0.0. - __ / __ / _____
Author: _____________________
Para compilar em uma janela de comandos (terminal):
No Linux : g++ -o Guia0201 ./Guia0201.cpp
No Windows: g++ -o Guia0201 Guia0201.cpp
Para executar em uma janela de comandos (terminal):
No Linux : ./Guia0205
No Windows: Guia0205
*/
// lista de dependencias
#include "karel.hpp"
// --------------------------- definicoes de metodos
/**
decorateWorld - Metodo para preparar o cenario.
@param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld(const char *fileName)
{
    // colocar paredes no mundo
    world->set(4, 4, VWALL);
    world->set(4, 4, HWALL);
    // colocar um marcador no mundo
    world->set(4, 4, BEEPER);

    world->save(fileName); // salvar a configuracao atual do mundo
} // end decorateWorld ( )

/**
Classe para definir robo particular (MyRobot),
a partir do modelo generico (Robot)
Nota: Todas as definicoes irao valer para qualquer outro robo
criado a partir dessa nova descricao de modelo.
*/

class MyRobot : public Robot
{
public:
    /**
    turnRight - Procedimento para virar 'a direita.
    */
    void turnRight()
    {
        // definir dado local
        int step = 0;
        // testar se o robo esta' ativo
        if (checkStatus())
        {
            // o agente que executar esse metodo
            // devera' virar tres vezes 'a esquerda
            for (step = 1; step <= 3; step = step + 1)
            {
                turnLeft();
            } // end for
        }     // end if
    }         // end turnRight ( )
    /**
    moveN - Metodo para mover certa quantidade de passos.
    @param steps - passos a serem dados.
    */
    void moveN(int steps)
    {
        // definir dado local
        int step = 0;
        // testar se a quantidade de passos e' maior que zero
        for (step = steps; step > 0; step = step - 1)
        {
            // dar um passo
            move();
        } // end if
    }     // end moveN( )

    /**
* pickBeepers - Metodo para coletar marcadores.
*/
/*void pickBeepers( )
{
// repetir (com teste no inicio)
// enquanto houver marcador proximo
while ( nextToABeeper( ) )
{
// coletar um marcador
pickBeeper ( );
} // end while
} // end pickBeepers( )*/



int pickBeepers ( )
{
// definir dado local
int n = 0;
// repetir (com teste no inicio)
// enquanto houver marcador proximo
while ( nextToABeeper ( ) )
{
// coletar um marcador
pickBeeper ( );
// contar mais um marcador coletado
n = n + 1;
} // end while
// retornar a quantidade de marcadores coletados
return ( n );
} // end pickBeepers( )



/**
doSquare - Metodo para especificar outro percurso.
*/
void doSquare( )
{
// definir dado local
int step = 1;
int n = 0;
char msg [80];
// especificar acoes da tarefa
while ( step <= 4 )
{
// realizar uma parte da tarefa
moveN(3);
n = pickBeepers ( );
if ( n > 0 )
{
// montar a mensagem para a saida
sprintf ( msg, "Recolhidos = %d", n );
// solicitar a exibicao da mensagem
show_Text ( msg );
} // end if
pickBeepers();
turnRight();
// tentar passar 'a proxima
step = step + 1;
} // end while
turnOff ( );
} // end doSquare( )
};    // end class MyRobot
// --------------------------- acao principal
/**
Acao principal: executar a tarefa descrita acima.
*/
int main()
{
    // definir o contexto
    // criar o ambiente e decorar com objetos
    // OBS.: executar pelo menos uma vez,
    // antes de qualquer outra coisa
    // (depois de criado, podera' ser comentado)
    world->create(""); // criar o mundo
    decorateWorld("Guia0205.txt");
    world->show();
    // preparar o ambiente para uso
    world->reset();              // limpar configuracoes
    world->read("Guia0205.txt"); // ler configuracao atual para o ambiente
    world->show();               // mostrar a configuracao atual
    set_Speed(3);                // definir velocidade padrao
    // criar robo
    MyRobot *robot = new MyRobot();
    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create(1, 1, EAST, 4, "Karel");
    // executar tarefa
     robot->doSquare();
    world->close(); // encerrar operacoes no ambiente
    // encerrar programa
    getchar();
    return (0);
} // end main ( )
  // -------------------------------------------- testes
  /*
  ---------------------------------------------- documentacao complementar
  ---------------------------------------------- notas / observacoes / comentarios
  ---------------------------------------------- previsao de testes
  ---------------------------------------------- historico
  Versao Data Modificacao
  0.1 __/__ esboco
  --------------------------------------------- testes
  Versao Teste
  0.1 01. ( ) identificacao de programa
  0.2 02. (OK)
  0.3 01. (OK)
  0.4 01 (OK)
  0.5 01 (OK)
  */

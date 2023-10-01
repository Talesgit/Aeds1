/* Guia0110 ver 0.0 26/02/2023
Autor: Tales Rocha Moreira
*/
// lista de dependencias
#include "karel.hpp" //(coment�rio: necessario estar na mesma pasta)
// --------------------------- definicoes de metodos
/**
decorateWorld - Metodo para preparar o cenario.
@param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld(const char *fileName)
{
    // colocar paredes no mundo
    world->set(4, 4, HWALL); // horizontal
    world->set(4, 4, VWALL); // vertical
    // colocar um marcador no mundo
    world->set(4, 4, BEEPER);
    // salvar a configuracao atual do mundo
    world->save(fileName);
} // decorateWorld ( )
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
        // testar se o robo esta' ativo
        if (checkStatus())
        {
            // o agente que executar esse metodo
            // devera' virar tres vezes 'a esquerda
            turnLeft();
            turnLeft();
            turnLeft();
        } // end if
    }     // end turnRight ( )
    /**
    moveN - Metodo para mover certa quantidade de passos.
    @param steps - passos a serem dados.
    */
    void moveN(int steps)

    {
        // repetir se a quantidade de passos e' maior que zero
        for (int step = 1; step <= steps; step = step + 1)
        {
            // outra forma de repetir

            // dar um passo por vez
            move();
        } // end if
    }     // end moveN()

    /**
    doPartialTask - Metodo para descrever parte de uma tarefa.
    */
    void doPartialTask()
    {

        // especificar acoes dessa parte da tarefa
        moveN(3);
        move();
        move();
        move();
        turnLeft();
    } // end doPartialTask( )
    /**
    doTask - Relacao de acoes para qualquer robo executar.
    */
    void doTask()
    {
        doPartialTask();
        doPartialTask();
        // testar se ha' marcador antes ...
        if (nextToABeeper())
        {
            pickBeeper();
        } // end if   //apanhar marcador
        doPartialTask();
        // testar se carrega marcador antes ...
        if (nbeepers() > 0)
        {
            putBeeper();
        } // end if  //colocar marcador
        doPartialTask();
        // executar
        move(); // andar
        move();
        turnLeft(); // virar 'a esquerda
        move();
        move();
        turnLeft();
        move();
        move();
        turnLeft();
        move();
        move();
        turnLeft();
        turnLeft();
        // encerrar
        turnOff(); // desligar-se
    }              // end doTask ( )
};                 // end class MyRobot
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
    decorateWorld("Guia0110.txt");
    world->show();
    // preparar o ambiente para uso
    world->reset();              // limpar configuracoes
    world->read("Guia0110.txt"); // ler configuracao atual para o ambiente
    world->show();               // mostrar a configuracao atual
    set_Speed(3);                // definir velocidade padrao
    // criar robo
    MyRobot *robot = new MyRobot();
    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create(1, 1, EAST, 0, "Karel");
    // executar tarefa
    robot->faceNorth();
    robot->moveN(3);
    robot->turnRight();
    robot->moveN(3);
    robot->pickBeeper();


    // robot->doTask();
    /*robot->move( ); // primeira acao: andar para frente
    robot->move( ); // outra acao : mover-se de novo
    robot->turnLeft( ); // virar 'a esquerda
    robot->move( );
    robot->move( );
    robot->turnLeft( );
    robot->move( );
    robot->move( );
    robot->turnLeft( );
    robot->move( );
    robot->move( );
    robot->turnLeft( );
    robot->turnLeft( );*/
    robot->turnOff(); // desligar-se
    // encerrar operacoes no ambiente
    world->close();
    // encerrar programa
    getchar();
    return (0);
} // end main ( )
// ------------------------------------------- testes
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
0.1 01. (OK) teste inicial
0.2 01  (OK) teste da tarefa
0.3 01  (OK) teste da tarefa parcial
0.4 01  (OK) teste do apanhador marcador
0.5 01  (OK) teste de colocar o marcador
0.6 01  (OK) teste da repeticao do movimento
0.7 01  (??) teste com e sem marcador no ponto (4.4)
0.8 01  (OK) teste com a quantidade de marcadores
0.9 01  (OK) teste com outra forma de repeticao
1.0 01  (??) teste com outra forma de repetição
    01  (??) teste com outra forma de alternativa
*/

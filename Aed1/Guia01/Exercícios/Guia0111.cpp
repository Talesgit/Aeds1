/*
Guia0110 - v0.11. - _27 / 02/ 2023
Author: _____Tales Rocha Moreira_____________________
*/
// lista de dependencias
#include "karel.hpp" //(comentario: necessario estar na mesma pasta)
// --------------------------- definicoes de metodos
/**
decorateWorld - Metodo para preparar o cenario.
@param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld(const char *fileName)
{
    // colocar paredes no mundo
    // world->set ( 2, 1, HWALL ); // horizontal
    // world->set ( 3, 2, HWALL ); // horizontal
    // /world->set ( 4, 3, HWALL ); // horizontal
    // world->set ( 4, 4, VWALL ); // vertical
    // colocar um marcador no mundo
    // world->set ( 3, 3, BEEPER );
    // world->set ( 6, 3, BEEPER );
    // world->set ( 6, 6, BEEPER );
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
        int step = 0;
        // repetir contando e testando ate' atingir a quantidade de passos
        for (step = 1; step <= steps; step = step + 1) // outra forma de repetir
        {
            // dar um passo por vez
            move();

        } // end if
    }     // end moveN( )
    /**
    doPartialTask - Metodo para descrever parte de uma tarefa.
    */
    void doPartialTask()
    {
        // especificar acoes dessa parte da tarefa

        moveN(0);
        move();
        move();
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
        // executar tarefa
        // robot->doTask();
        move();     // primeira acao: andar para frente
        move();     // outra acao : mover-se de novo
        turnLeft(); // virar 'a esquerda
        move();
        move();

        putBeeper();

        move();
        // executar
        /*
        doPartialTask();
        doPartialTask();
        //testar se ha' marcador antes ...
        if (nextToABeeper())
        {
            // pickBeeper( ); // apanhar marcador
        } // end if
        doPartialTask();
        // testar se carrega marcador antes ...
        if (nbeepers() > 0)
        {
            // putBeeper( ); // colocar marcador
        } // end if
        doPartialTask();
        // move( ); // andar
        // move( );
        turnLeft(); // virar 'a esquerda
        // move( );
        // move( );
        turnLeft();
        // move( );
        // move( );
        putBeeper();
        turnLeft();
        // move( );
        // move( );
        turnLeft();
        turnLeft();
        // encerrar
        turnOff(); // desligar-se
        */
    } // end doTask ( )
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
    decorateWorld("Guia0111.txt");
    world->show();
    // preparar o ambiente para uso
    world->reset();              // limpar configuracoes
    world->read("Guia0111.txt"); // ler configuracao atual para o ambiente
    world->show();               // mostrar a configuracao atual
    set_Speed(2);                // definir velocidade padrao
    // criar robo
    MyRobot *robot = new MyRobot();
    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create(1, 1, EAST, 3, "Karel");
    // robot->create ( 6, 6, EAST, 0, "Karel" );

    // executar tarefa
    // robot->doTask();
    robot->move();     // primeira acao: andar para frente
    robot->move();     // outra acao : mover-se de novo
    robot->turnLeft(); // virar 'a esquerda
    robot->move();
    robot->move();
    robot->putBeeper();
    robot->turnRight();
    robot->move();
    robot->move();
    robot->move();
    robot->putBeeper();
    robot->faceNorth();
    robot->move();
    robot->move();
    robot->move();
    robot->putBeeper();
    robot->turnLeft();
    robot->move();
    robot->move();
    robot->move();
    robot->move();
    robot->move();
    robot->turnLeft();
    robot->move();
    robot->move();
    robot->move();
    robot->move();
    robot->move();
    robot->turnLeft();

    /*robot->move();
    robot->putBeeper();

    robot->turnLeft();
    robot->move();
    robot->move();
    robot->turnLeft();
    robot->move();
    robot->move();
    robot->turnLeft();
    robot->turnLeft();
    robot->turnOff(); // desligar-se*/
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
0.1 01. ( ) identificacao de programa
*/

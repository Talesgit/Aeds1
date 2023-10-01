#include "myKarel.hpp"
void decorateWorld(const char *fileName)
{
    // colocar paredes no mundo
    world->set (3, 1, HWALL );
    world->set (4, 1, HWALL );
    world->set (4, 2, VWALL );
    world->set (5, 2, HWALL );
    world->set ( 5, 2, VWALL );
    world->set (6, 1, HWALL );
    world->set (7, 1, HWALL );
    world->set (7, 2, VWALL );
    world->set (7, 3, VWALL );
    world->set (6, 3, HWALL );
    world->set (7, 3, HWALL );
    world->set ( 5, 4, VWALL );
    world->set (6, 4, HWALL );
    world->set (7, 4, HWALL );
    world->set (7, 5, VWALL );
    world->set (7, 6, VWALL );
    world->set (7, 6, HWALL );
    world->set (6 ,6, HWALL );
    world->set (5, 6, VWALL );
    world->set (5, 5, HWALL );
    world->set (4, 6, VWALL );
    world->set (4, 6, HWALL );
    world->set (3, 6, HWALL );
    world->set (2, 6, VWALL );
    world->set (2, 5, VWALL );
    world->set (3, 4, HWALL );
    world->set (4, 4, HWALL );
    world->set (4, 4, VWALL );
    world->set (4, 3, HWALL );
    world->set (3, 3, HWALL );
    world->set (2, 2, VWALL );
    world->set (2, 3, VWALL );





// colocar um marcador no mundo
    world->set ( 5, 6, BEEPER );
    world->set ( 4, 4, BEEPER );
    world->set ( 5, 2, BEEPER );
    world->set ( 6, 4, BEEPER );

    world->save(fileName); // salvar a configuracao atual do mundo
} // end decorateWorld ( )

int main()
{
    // definir o contexto
    // criar o ambiente e decorar com objetos
    // OBS.: executar pelo menos uma vez,
    // antes de qualquer outra coisa
    // (depois de criado, podera' ser comentado)
    world->create(""); // criar o mundo
    decorateWorld("Guia0212.txt");
    world->show();
    // preparar o ambiente para uso
    world->reset();              // limpar configuracoes
    world->read("Guia0212.txt"); // ler configuracao atual para o ambiente
    world->show();               // mostrar a configuracao atual
    set_Speed(1.8);                // definir velocidade padrao
    // criar robo
    MyRobot *robot = new MyRobot();
    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create(1, 1, EAST, 0, "Karel");
    // executar tarefa
    robot->doSquare();



    world->close(); // encerrar operacoes no ambiente
    // encerrar programa
    getchar();
    return (0);
} // end main ( )

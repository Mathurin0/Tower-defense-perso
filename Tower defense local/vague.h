#include <iostream>
#include <time.h>
using namespace std;

public class WaveSpawner : WaveSpawner {

    private float BetweenWaves = 10;

    private transform SpawnPoint;

    private float Coutdown = 5;

    private int waveNumber = 1;

    void update() {
        if (Coutdown <= 0) {
            Wave1();
            Coutdown = BetweenWaves
        }
        Coutdown--;
    }

    void Wave1() {
        for (int i = 0; i < waveNumber; ++i) {
            SpawnEnnemy1();
            Delay(1000);
        }
        cout << "Nouvelle Vague" << endl;
        waveNumber++;
    }

    /*
    void Wave2(){
        for (int i = 0; i < ; ++i) {
            SpanwEnnemy2();
            delay(1000);
        }
     }
    void SpawnEnnemy2(){
        //20 Zombie/5 tank
    }
         void Wave3(){
        for (int i = 0; i < ; ++i) {
            SpanwEnnemy2();
            delay(1000);
        }
     }
    void SpawnEnnemy3(){
        //30 Zombie/15 Tank/50 Runner
    }
     */
    void SpawnEnnemy1() {
        instantiate(Ennemy, SpawnPoint.position, SpawnPoint.rotation);
    }
};
//inkludering av bibloteker
#include "threepp/threepp.hpp"
#include <math.h>
#include <vector>
#include <memory>
#include <random>
//lister
using namespace threepp;

struct Liste : KeyListener {
    //Liste (auto bl, auto blo): math1(bl), math2(blo){

   // }
    //void onKeyPressed(KeyEvent evt) override
   // {
       // if (evt.key ==Key::SPACE) {



          // if (amountCliked %2 ==0) {
              //  math1->color= Color::white;
           // }
           // else {
            //    math2->color= Color::green;
            //}
           // amountCliked++;


        //}
    //}

   // Liste(auto bl, auto blo) : math1(bl), math2(blo) {}


        Liste(auto bl, auto blo) : math1(bl), math2(blo) {}

        void onKeyPressed(KeyEvent evt) override {
            if (evt.key == Key::SPACE)
                {
                index=index+1;

                if (index %2==0) {
                    math1->color=Color(randomFloat(), randomFloat(), randomFloat());

                }
                else {
                    math2->color= Color(randomFloat(), randomFloat(), randomFloat());
                }



            }
        }

    private:
    //legg til en til variabel 
        std::shared_ptr<MeshBasicMaterial> math1{};
        std::shared_ptr<MeshBasicMaterial> math2{};
        int index = 0;

        // Random generator
        float randomFloat() {
            static std::random_device rd;
            static std::mt19937 gen(rd());
            static std::uniform_real_distribution<float> dist(0.0f, 1.0f);
            return dist(gen);
        }
    };


//private:
   // std::shared_ptr<MeshBasicMaterial> math1{};
  //  std::shared_ptr<MeshBasicMaterial> math2{};
  //  int amountCliked = 0;

//};
int main() {
    Canvas canvas;
    GLRenderer renderer(canvas.size());

    Scene scene; //et objeckt
    PerspectiveCamera camera(60, canvas.aspect(),0.1,1000);
    camera.position.z=5;
    auto LIKGEOMETRI = SphereGeometry::create(0.3);

    ///auto utsende_form = Mesh::create(LIKGEOMETRI, hvordan_objekt_ser_ut);
    //scene.add(utsende_form);

    std::vector<std::shared_ptr<Mesh>> vectorName;


    auto hvordan_objekt_ser_ut1= MeshBasicMaterial::create();
    auto hvordan_objekt_ser_ut2= MeshBasicMaterial::create();
    hvordan_objekt_ser_ut1->color = Color::blue;
    hvordan_objekt_ser_ut2->color = Color::blue;
    for (int i= 0; i<8; i++) {
        std::shared_ptr<MeshBasicMaterial> matrial{};
        if (i%2==0) {
            matrial = hvordan_objekt_ser_ut1;

        }
        else  {
            matrial= hvordan_objekt_ser_ut2;
        }
        auto utsende_form = Mesh::create(LIKGEOMETRI, matrial);
        utsende_form->position.x = -4+i;
        vectorName.push_back(utsende_form);
        scene.add(utsende_form);
    }

    auto keyController = std::make_unique<Liste>(hvordan_objekt_ser_ut1, hvordan_objekt_ser_ut2);
    canvas.addKeyListener(*keyController);

    float count=0.0;
    canvas.animate([&] {
     renderer.render (scene,camera);
        //utsende_form->position.y=std::sin(count);
        for (int i=0; i <vectorName. size (); i++) {
            if (i % 2==0) {
                vectorName[i]->position.y=std::sin(count);
            }
            else {
                vectorName [i]->position.y=-std::sin(count);
            }
        }

        count+=0.03;


    }
        );

    return 0;
}
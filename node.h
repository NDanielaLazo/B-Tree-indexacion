#ifndef NODE_H_
#define NODE_H_
#include <vector>
#include <algorithm> //fill
#include <iostream>

template <class T>
class node
{
public:
    /* nodo de grado n puede tener hasta n hijos y n-1 claves reserva espacio
    para n teclas para que el vector no cambie de tamaño en desbordamiento */
    node(unsigned int dgree);
    node(unsigned int dgree,const std::pair<unsigned int,T> &pear);
    node(unsigned int dgree,const std::pair<unsigned int,T> &pear,node<T> *left,node<T> *right);
    //Obteniendo:
    unsigned int getDegree(){return degree;}
    unsigned int getMaxKeys(){return 2 * degree - 1;}//puede cambiar
    unsigned int getNumKeys(){return keys.size();}
    unsigned int getNumChilds(){return childs.size();}
    node<T>* getParent(){return parent;}
    bool isLeaf(){return childs.size()==0;} //retorna true si no tiene hijo
    unsigned int getIndexToInsert(unsigned int keyValue); //retorna el índice más cercano basado en la clave
    int getKeyVal(unsigned int index); //retorna la clave en el índice, -1 si está fuera de los límites
    std::pair<unsigned int,T> getPair(unsigned int index);
    node<T>* getChild(unsigned int index); //retorna puntero a nodo en el index

    T getData(unsigned int keyValue); //retorna el dato de la llave
    node<T>* getNodeToTraverse(std::pair<unsigned int, T> &pear); //retorna el nodo del pair standar (tupla)
    node<T>* getNodeToTraverse(unsigned int keyValue); //returns node from key
    //Poniendo o dando:
    void setParent(node<T> *nd){parent=nd;}
    //funciones:
    void insert(const std::pair<unsigned int, T> &pear,node<T>* childPtr=nullptr);
        //bool deleteKey(unsigned int keyValue);
    int searchNode(unsigned int keyValue);

    bool removeKey(unsigned int index);
    bool removeChild(unsigned int index);
    void addKeyToBack(std::pair<unsigned int,T> &pear);
    void addChildToBack(node* child);
    void insertKeyAtIndex(std::pair<unsigned int,T>pear,unsigned int i);
    void insertChildAtIndex(node* child, unsigned int i);
    void setChild(node* child, unsigned int index){childs[index] = child;}
    void setLeaf(bool val){leaf=val;}
    void insert(unsigned int keyValue, node<T> *childPtr=nullptr);
    void setKey(unsigned int idx, std::pair<unsigned int, T> &pear){keys[idx] = pear;}
    void insertKeyIntoNode(const std::pair<unsigned int, T> &pear);
    //Propiedades:
    //Sobrecargas:
    template <class U> //Imprime el valor del dato en el nodo
        friend std::ostream& operator<< (std::ostream &out, node<T> &nd);
    T& operator[] (unsigned int index); //retorna el dato del index

private:

    //propiedades:
    unsigned int degree; // t, numero mínimo de hijos
    unsigned int maxKeys; //máximo llaves, 2t-1
    bool leaf; //sin hijos, true
    node<T>* parent; //puntero pariente
    //objectos:
    std::vector<std::pair<unsigned int,T> > keys; //vector de las llaves y sus datos
    std::vector<node<T>*> childs; //vector punteros a hijos
};

#include "node.cpp"

#endif

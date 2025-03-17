// Por: Lenin Enrique García Caraballo y David Orlando Riaño Morales
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        
        vector<int> twoSum(vector<int>& nums, int target) { // Se crea una función miembro de la clase

            int suma_temp = 0; // Se crea una variable temporal para almacenar la suma

            int size_vector = nums.size(); // Se crea una variable para almacenar el tamaño del vector

            vector<int> salida;
            int modificacion;
            // Se recorre el vector de números
            // Se toma un valor de referencia en el vector, inicialmente num[0]
            for(int i = 0; i < size_vector; i++){
                // Se crea una variable de módificación de posición para el otro contador o recorrido del vector
                modificacion = i + 1;
                // Va a haber un valor num[j] que va a tomar los valores siguientes a num[i], va a ir cambiando de posición
                for(int j = modificacion; j < size_vector; j++){
                    // Se define una variable de suma temporal
                    suma_temp = nums[i] + nums[j];
                    // A medida que j aumente, suma_temporal va a tomar un nuevo valor de num[i] + num[j] que será evaluado en una condición

                    /*Si suma_temp es igual a target, es porque se encontraron los dos números en el vector, cuya
                    suma da el target*/
                    if(suma_temp == target){
                        // Se retornan en un vector de enteros las posiciones de los dos números
                        return {i,j};
                    }

                    // En caso de que suma_temp no haya dado el target cuando se aumentó a j, se reinicia a 0 la variable suma_temp
                    else{
                        // Se reinicia para poder evaluar la suma del valor de referencia num[i] y el nuevo valor num[j]
                        suma_temp = 0;
                    }

                    /* Si al recorrer todo el vector, teniendo un valor de referencia num[i] dado no se logra que la suma sea
                    igual al target, entonces se agarra un nuevo valor de referencia num[i] (debido a que i se va a incrementar en 1)
                    y se repite el proceso anterior así hasta que sum_temp = target*/
                }  
            }
            /* En caso de haber probado con todos los elementos del vector como valores de referencia num[i] y que en ningún caso 
            suma_temp = target, se concluye que no hay dos números cuya suma de como resultado a target y se retorna un vector de posiciones
            enteras vacío */
            return {};
        }
    };

    int main(int, char **){
        cout << "Ejercicio 1.twosum " << endl;
        // Se crea un objeto
        Solution obj1;

        // Se evalua el método twosum en la clase Solution con los casos prueba de leetcode
        // CASO #1
        vector<int> arreglo_entrada = {2,7,11,15};
        int tar = 9;
        vector<int> resultado;
        resultado = obj1.twoSum(arreglo_entrada, tar);
        cout << "[" << resultado[0] << ", " << resultado[1] << "]" << endl;

        // CASO #2
        arreglo_entrada = {3,2,4};
        tar = 6;
        resultado = obj1.twoSum(arreglo_entrada, tar);
        cout << "[" << resultado[0] << ", " << resultado[1] << "]" << endl;

        // CASO #3
        arreglo_entrada = {3,3};
        tar = 6;
        resultado = obj1.twoSum(arreglo_entrada, tar);
        cout << "[" << resultado[0] << ", " << resultado[1] << "]" << endl;

        return 0;
    }
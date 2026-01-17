/*Написать компьютерную программу, содержащую
 - Описание классов vect и matr, содержащие поля int dim, double*b (double*a), int num, static int count;
dim – размерность, a и b – компоненты матрицы и вектора, num – номер объекта, count – количество объектов, созданных программой.
 - Конструкторы и деструктор, содержащие вывод сообщений о выполненном действии и номерах участвующих объектов;
 - Набор оператор-функций (компонентных и внешних) для операций векторной алгебры, содержащих вывод сообщений о выполненных действиях и номерах участвующих объектов:
     v+v, v-v, -v, v*v, k*v, v=v,
     m+m, m-m, -m, m*m, k*m, m=m,
     m*v.
 - Функцию main, содержащую сценарий работы с векторами и матрицами.*/

#include <iostream>
#include <string>
using namespace std;
class vect{
    public:
    int dim;
    double* a;
    int num;
    static int count;
    // Конструктор с параметром (размерность)
    vect(int dim) : dim(dim), num(++count) {
        a = new double[dim];
        cout << "Создан вектор #" << num << " (размерность " << dim << ")" << endl;
    }
    // Конструктор копирования
    vect(const vect& other) : dim(other.dim), num(++count) {
        a = new double[dim];
        for (int i = 0; i < dim; i++) {
            a[i] = other.a[i];
        }
        cout << "Создан вектор #" << num << " (копия вектора #" << other.num << ")" << endl;
        }
    ~vect(){
        delete[] a;
        cout << "Удалён вектор #" << num << endl;
    }
    void print() const {
        cout << "Вектор #" << num << ": (";
        for (int i = 0; i < dim; i++) {
            cout << a[i];
            if (i < dim - 1) cout << ", ";
        }
        cout << ")" << endl;
    }
    vect operator+(const vect& other) {
        cout << "Сложение векторов #" << this->num << " и #" << other.num <<endl;
        vect newvector(dim);
        for (int i=0; i<dim; i++){
            newvector.a[i] = a[i]+other.a[i];
        }
        return newvector;
    }
    vect operator-(const vect& other) {
        cout << "Вычитание векторов #" << this->num << " и #" << other.num <<endl;
        vect newvector(dim);
        for (int i=0; i<dim; i++){
            newvector.a[i] = a[i]-other.a[i];
        }
        return newvector;
    }
    vect operator*(const vect& other) {
        cout << "Умножение векторов #" << this->num << " и #" << other.num << endl;
        vect newvector(dim);
        for (int i=0; i<dim; i++){
            newvector.a[i] = a[i]*other.a[i];
        }
        return newvector;
    }
    vect operator-() {
        cout << "Отрицание вектора #" << this->num<<endl;
        vect newvector(dim);
        for (int i=0; i<dim; i++){
            newvector.a[i] = -a[i];
        }
        return newvector;
    }
    vect operator*(int k) {
        cout << "Умножение вектора на константу #" << this->num <<endl;
        vect newvector(dim);
        for (int i=0; i<dim; i++){
            newvector.a[i] = a[i]*k;
        }
        return newvector;
    }
    vect operator=(const vect& other){
        cout << "Присваивание вектора #" << this->num << " вектору #" << other.num<< endl;
        for (int i=0; i<dim; i++){
            a[i]=other.a[i];
        }
        return *this;
    }
};int vect::count=0;
class matr{
    public:
    int dim;
    double* b;
    int num;
    static int count;
    // Конструктор с параметром (размерность)
    matr(int dim) : dim(dim), num(++count) {
        b = new double[dim*dim];
        cout << "Создана матрица #" << num << " (размерность " << dim<< ")" << endl;
    }
    // Конструктор копирования
    matr(const matr& other) : dim(other.dim), num(++count) {
        b=new double[dim*dim];
        for (int i=0; i<dim;i++){
            for (int j=0; j<dim;j++){
                b[i*dim+j]=other.b[i*dim+j];
            }
        }
        cout << "Создана матрица #" << num << " (копия матрицы #" << other.num << ")" << endl;
    }
    ~matr(){
        delete[] b;
        cout << "Удалена матрица #" << num << endl;
    }
    void print() const {
        cout << "Матрица #" << num << ":" << endl;
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                cout << b[i * dim + j] << "\t";
            }
            cout << endl;
        }
    }
    matr operator+(const matr& other){
        cout << "Сложение матриц #" << this->num << " и #" << other.num <<endl;
        matr newmatr(dim);
        for (int i=0; i<dim; i++){
            for (int j=0; j<dim; j++){
                newmatr.b[i*dim+j]=b[i*dim+j]+other.b[i*dim+j];
            }
        }
        return newmatr;
    }
    matr operator-(const matr& other){
        cout << "Вычитание матриц #" << this->num << " и #" << other.num <<endl;
        matr newmatr(dim);
        for (int i=0; i<dim; i++){
            for (int j=0; j<dim; j++){
                newmatr.b[i*dim+j]=b[i*dim+j]-other.b[i*dim+j];
            }
        }
        return newmatr;
    }
    matr operator*(const matr& other){
        cout << "Умножение матриц #" << this->num << " и #" << other.num <<endl;
        matr newmatr(dim);
        for (int i=0; i<dim; i++){
            for (int j=0; j<dim; j++){
                newmatr.b[i*dim+j]=b[i*dim+j]*other.b[i*dim+j];
            }
        }
        return newmatr;
    }
    matr operator-(){
        cout << "Отрицание матрицы #" << this->num<<endl;
        matr newmatr(dim);
        for (int i=0; i<dim; i++){
            for (int j=0; j<dim; j++){
                newmatr.b[i*dim+j]=-b[i*dim+j];
            }
        }
        return newmatr;
    }
    matr operator*(double c){
        cout << "Умножение матрицы #" << this->num<<" на константу "<<c<<endl;
        matr newmatr(dim);
        for (int i=0; i<dim; i++){
            for (int j=0; j<dim; j++){
                newmatr.b[i*dim+j]=b[i*dim+j]*c;
            }
        }
        return newmatr;
    }
    matr operator=(const matr& other){
        cout << "Присваивание матрице #" << this->num<<" матрицу "<<other.num<<endl;
        b = new double[dim * dim];
        for (int i=0; i<dim; i++){
            for (int j=0; j<dim; j++){
                b[i*dim+j]=other.b[i*dim+j];
            }
        }
        return *this;
    }
    vect operator*(const vect& vector){
        if (this->dim != vector.dim){
            cout << "Размерности матрицы и вектора не совпадают!" << endl;
        }
        else{
            cout << "Умножение матрицы #" << this->num << " на вектор #" << vector.num << endl;
            vect matr_vect(this->dim);
            for (int i=0;i<this->dim;i++){
                matr_vect.a[i]=0;
                for (int j=0; j<this->dim;j++) {
                    matr_vect.a[i]+=b[i*this->dim+j]*vector.a[j];
                }
            }
            return matr_vect;
        }
    }
};int matr::count=0;
int main(){
    int k=1;
    int c=1;
    vect vector1(2);
    vector1.a[0]=1.0;
    vector1.a[1]=2.0;
    vect vector2(vector1);
    vect newvector=vector1+vector2;
    newvector.print();
    newvector=vector1-vector2;
    newvector.print();
    newvector=vector1*vector2;
    newvector.print();
    newvector=-vector1;
    newvector.print();
    newvector=vector1*k;
    newvector.print();
    vector1=vector2;
    matr matrix1(2);
    matrix1.b[0]=1.0;
    matrix1.b[1]=2.0;
    matrix1.b[2]=3.0;
    matrix1.b[3]=4.0;
    matr matrix2(matrix1);
    matr newmatrix=matrix1+matrix2;
    newmatrix.print();
    newmatrix=matrix1-matrix2;
    newmatrix.print();
    newmatrix=matrix1*matrix2;
    newmatrix.print();
    newmatrix=-matrix1;
    newmatrix.print();
    newmatrix=matrix1*c;
    newmatrix.print();
    matrix1=matrix2;
    newmatrix.print();
    vect matr_vect=matrix1*vector1;
    matr_vect.print();
    return 0;
}


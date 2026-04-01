
constexpr int foo( int b){
    //constexpr int b2 = b; // main.cpp:4:19: error: constexpr variable 'b2' must be initialized by a constant expression
    int b2 = b;
    return goo(b2);
}
int main(){
    constexpr int a = 5;
    foo(a);
}
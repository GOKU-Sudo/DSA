class student{
      public:
        int age;
        const int rollnumber;
        int &x;// age reference variable 
        student(int r,int age): rollnumber(r), age(age), x(this->age) {

        }
};


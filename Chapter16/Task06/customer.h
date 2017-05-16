//customer.h 
#ifndef CUST_H_
#define CUST_H_

// ta kolejka będzie przechowywała elementy klasy Customer
class Customer
{
    private:
        long arrive;     // czas dołączenia klienta do kolejki
        int processtime; // czas obsługi klienta
    public:
        Customer() { arrive = processtime = 0; }
        void set(long when);
        long when() const { return arrive; }
        int ptime() const { return processtime; }
};
#endif


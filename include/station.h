#ifndef STATION_H
#define STATION_H

class Station {
public:
    virtual void DoWork(int& workpiece) = 0;
    virtual int GetNextStation() = 0;
    Station() = default;
    virtual ~Station() = default;
};

class Station_A : public Station {
public:
    void DoWork(int& workpiece) override;
    int GetNextStation() override;
    ~Station_A() = default;
};

class Station_B : public Station {
public:
    void DoWork(int& workpiece) override;
    int GetNextStation() override;
    ~Station_B() = default;
};

class Station_C : public Station {
private:
    bool skip_next_station = false;

public:
    void DoWork(int& workpiece) override;
    int GetNextStation() override;
    ~Station_C() = default;
};

#endif
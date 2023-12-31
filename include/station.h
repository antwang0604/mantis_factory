#ifndef STATION_H
#define STATION_H

/**
 * @brief Fundemental Build Block Stations.
 * 
 */
class Station {
public:  

    /**
     * @brief Construct a new Station object
     * 
     */
    Station() = default;
    
    /**
     * @brief Destroy the Station object
     * 
     */

    virtual ~Station() = default;
    /**
     * @brief Perform specific operation on workpiece passed in. Must be overriden
     * 
     * @param workpiece piece to run through station
     */
    virtual void DoWork(int& workpiece) = 0;

    /**
     * @brief Determines where the next station is
     * 
     * @return int how many station to increment into along the assembly line
     */
    virtual int GetNextStation() = 0;
};

/**
 * @brief Station A - Adder
 * 
 */
class Station_A : public Station {
public:

    /**
     * @brief Destroy the Station_A object
     * 
     */
    ~Station_A() = default;
    
    /**
     * @brief Add 1 to the workpiece
     * 
     * @param workpiece 
     */
    void DoWork(int& workpiece) override;

    /**
     * @brief Returns 1 always to advance to next station
     * 
     * @return int 
     */
    int GetNextStation() override;
};

/**
 * @brief Station B - Subtractor
 * 
 */
class Station_B : public Station {
public:

    /**
     * @brief Destroy the Station_B object
     * 
     */
    ~Station_B() = default;

    /**
     * @brief Subtracts 1 to the workpiece
     * 
     * @param workpiece 
     */
    void DoWork(int& workpiece) override;
    
    /**
     * @brief Returns 1 always to advance to next station
     * 
     * @return int 
     */
    int GetNextStation() override;
};

/**
 * @brief Station C - Diverter
 * 
 */
class Station_C : public Station {
private:
    bool skip_next_station = false;

public:

    /**
     * @brief Destroy the Station_C object
     * 
     */
    ~Station_C() = default;

    /**
     * @brief Determine whether to skip the next station based on workpiece value.
     * 
     * @param workpiece 
     */
    void DoWork(int& workpiece) override;

    /**
     * @brief Return 1 if not skipping next station and 2 if skipping.
     * 
     * @return int 
     */
    int GetNextStation() override;
};

#endif
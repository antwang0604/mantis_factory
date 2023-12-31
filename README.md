# Mantis Factory Simulation Software
## Introduction
Mantis Factory Simulation Software is a tool that can help simulate a factory production line. A factory is consisted of one, or more assembly lines that can perform an operation on a workpiece to form the desired final product. An assembly line is composed of work stations, each performing a specific value adding operation to the workpiece.

In the Mantis factory, everything is configurable to form a flexible production line. The user can configure the assembly line with different kinds of workstations to produce variable products. The Mantis factory is also highly intelligent by tracking build records so the production data can be stored and used for additional analysis or applications.

## Repo Structure
### Important Classes
- Station - the fundemental building block of assembly lines. Unique stations (Station_A, Station_B ...) are inherited from the base class **Station**. Station A is currently configure to add 1 to the workpiece. Station B is currently configured to subtract 1 to the workpiece. Station C diverts the workpiece base on the workpiece. If the workpiece is odd valued, it diverts the workpiece to the next station; if the workpiece is even valued, it diverts the workpiece the next next station (skip one) depending on the workpiece.

- Assembly Line - The collection of stations that can take an input (raw material) and produce an output (final product). The assembly line also tracks the build records.  

- Factory - the main component that houses the assembly lines and the outter interface for external clients.  

- Line Configuration - The helper class to configure assembly lines, read user inputs, read and write from the configuration file (more info on the configuration file below).


### File Structure
The header files are located in the include folder. The cpp files are located in the src folder. The cmake generated files should be generated into the build folder.
### Configuration File
The file **assm_line_config.txt** is located in the top level directory. **This file is extremely important** because it is used for saving the most recent assembly line configuration and critical for the functionality to load previous session's assembly line configuration. If you accidentally delete it, please add an empty file with:  
`cd {$PATH_TO_MANTIS_FACTORY_REPO} && touch assm_line_config.txt` 


## Compilation Process
This software uses cmake and make for the compilation process. To build the executable, first, you want to navigate to the build directory  
`cd {$PATH_TO_MANTIS_FACTORY_REPO}/build`  
Next, use Cmake to automatically generate the make file  
`cmake ..`  
the make file will be generated inside the build directory. Next, we can compile the executable:  
`make .`  
This will generate the binary **RunMantisFactory** in the top level directory.

## Operational Instructions
### Main Menu Breakdown
The main menu displays the current assembly line configuration for your reference. It also displays the different operations you can perform.
![Menu](https://github.com/antwang0604/mantis_factory/blob/main/img/menu.png)

### Selection Modes:
- Configure Assembly Line: If you desire to change the assembly line configuration, enter 1. You will then need to enter the desired configuration for the new assembly line.
- Run Assembly Line: If you desire to run the assembly line, enter 2. You will then need to enter the input (raw material) you would like to run through the line.
- Print Total Station Utilization Record: If you desire to print the total station utilization record from the current session, enter 3.
- Print Build Logs: If you desire to print out the build logs to look at detail statistics from previous production runs, enter 4.

### Prerequisites:

- Locate the executable file called **RunMantisFactory** , it should be in the folder mantis_factory. If you cannot locate the executable, follow the compilation process above.
- Confirm that the configuration file is present in the same directoy as executable file **RunMantisFactory**
- Open up a terminal and confirm that you're currently in the directory where the executable and the configuration file is located.

### Standard Operational Procesdure:

1. Launch the program by entering the command `./RunMantisFactory`
2. Wait for the program to completely launch and you will be greeted with the main menu.
3. There are 4 different operations you can choose. Select the desired operation you would like to perform. You can reference the section **Selection Modes** to understand more about each function.
4. Continue step 3 until you are complete. Enter -1 to exit the program.

EXAMPLE:
- You want to configure the assembly line as station A -> station A
- You want to run the raw material of value 1 through the production line.
- You want to configure the assembly line as station A -> B -> C -> B -> A
- You want to run the raw material of value 2 through the production line.
- You want to examine the build logs, it should show:
  - production run 1 input is 1, output is 3.
  - production run 2 input is 2, output is 3.
- You want to examine the station utilization logs. Station A should have ran 4 times, while station B and C should have ran 1 time.

1. Start with an empty assembly line  
![Step 1](https://github.com/antwang0604/mantis_factory/blob/main/img/Step1.png)
2. Select (1) to configure the assembly line  
![Step 2](https://github.com/antwang0604/mantis_factory/blob/main/img/Step2.png)
3. Enter the raw material value 1 to run assembly line  
![Step 3](https://github.com/antwang0604/mantis_factory/blob/main/img/Step3.png)
4. Configure assembly line to ABCBA and run raw material 2 through line  
![Step 4](https://github.com/antwang0604/mantis_factory/blob/main/img/Step4.png)
5. View the build logs by entering 4  
![Step 5](https://github.com/antwang0604/mantis_factory/blob/main/img/Step5.png)
6. View the utilization logs by entering 3  
![Step 6](https://github.com/antwang0604/mantis_factory/blob/main/img/Step6.png)

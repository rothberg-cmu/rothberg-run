# Rothberg Run!
Rothberg Run! is a keyboard-controlling temple-run-like game written in C++.   
**[ENTER]**: start &emsp; **[ESC]**: exit game  
**[&larr;]**: shift left &emsp; **[&rarr;]**: shift right &emsp; **[SPACE]**: jump  
**[A]**: turn left &emsp; **[D]**: turn right  
The final **score** is calculated based on the **mileage** and **coins** collected. Game ends when player is out of road and scores gets
deducted everytime player encounters the **fence**.  The player's history record will be stored in a .txt file and displayed in the leaderboard in the end.  
## Features
  &emsp; &emsp; &emsp; &emsp; &emsp;**Game Start** &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; **Game Over**  
<img src="https://github.com/rothberg-cmu/rothberg-run/blob/jumpFixed/result/gameStart.png" width=37% height=37%>&nbsp;&emsp;&emsp;
 <img src="https://github.com/rothberg-cmu/rothberg-run/blob/jumpFixed/result/gameOver.png" width=37% height=37%>  
  &emsp; &emsp; &emsp;&emsp; &emsp; **Running** &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp;&emsp; &emsp;  **Jumping**  
<img src="https://github.com/rothberg-cmu/rothberg-run/blob/jumpFixed/result/running.png" width=37% height=37%>&nbsp;
<img src="https://github.com/rothberg-cmu/rothberg-run/blob/jumpFixed/result/jump.png" width=37% height=37%>    
  &emsp; &emsp; &emsp;&emsp; &emsp; **Shift** &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp; &emsp;&emsp; &emsp;  **Bird View**  
<img src="https://github.com/rothberg-cmu/rothberg-run/blob/jumpFixed/result/shift.png" width=37% height=37%>&nbsp;
<img src="https://github.com/rothberg-cmu/rothberg-run/blob/jumpFixed/result/birdView.png" width=37% height=37%>  
## Dependencies  
C++ &emsp; [OpenGL](https://www.opengl.org/) &emsp; [Soji's library](https://github.com/captainys/public)
## Build and Run  
### Linux
```
$  git clone https://github.com/rothberg-cmu/rothberg-run.git  
$  cd rothberg-run  
$  mkdir build  
$  cd build  
$  cmake ../src  
$  cd 3d-construction  
$  make  
$  ./3d-construction  
```  
### Mac  
```
```   
### Windows
First you need to have visual studio or other cpp compiler on your windows and download the source code to your machine. Then go to the folder where you unzip the source code, make a folder called build which locates at the same level or the src folder and run following command in the Powershell.
```
$  cd build
$  cmake ../src
```  
After running these commands, you will find Project.sln in your build folder. Then what you need to do is to open this file with visual studio and compile the 3d-construction program.

To run the program, go into the folder where the 3d-construction.exe locates and double click on it. 
## Composition 
**3d-construction:** 3d construction  
**data:** all .stl files needed  
**map-generation:**  generate maps  
**public:** soji's library  
**camera:** camera  
**coins:**  draw coins  
**game-player:** calculate player's position in real time  
**obstacle:** obstacles like fences 
## Contributor  
[Boxian Deng](https://github.com/eastlife)&emsp; [Zi Li](https://github.com/ziliHarvey)&emsp; [Minjun Xu](https://github.com/wx9698)&emsp; [Jing Zhao](https://github.com/jingzhao3200)  
## License  
## Reference
All stl files are downloaded from [TURBOSQUID](https://www.turbosquid.com/)&emsp;

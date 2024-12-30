<h1>Sudoku Game</h1>
<br>
<h3>For the first build, run the following:</h3>
<ol>
  <li>mkdir build</li>
  <li>cd build</li>
  <li>cmake ..</li>
</ol>
<br>
<h3>For additional builds, run the following:</h3>
<ol>
  <li>make</li>
  <li>./main</li>
</ol>
<br>
<h3>Debugging Symbols:</h3>
<ul>
  <li>cmake .. -DCMAKE_BUILD_TYPE=Debug</li>
  <li>make</li>
  <li>lldb ./main</li>
  <li>r</li>
  <li>bt (to look at backtrace)</li>
  <li>f 4 (to look at frame 4 for example)</li>
  <li>p <variable> to print variable's value</li>
  <li>q to quit</li>
  <li>y for yes</li>
</ul>
<br>
<h3>To do:</h3>
<ol>
  <li>Make the game prettier using box drawing characters
https://en.m.wikipedia.org/wiki/Box-drawing_characters</li>
  <li>Make different starting boards of varying difficulty</li>
  <li>Make sudoku game solver</li>
</ol>

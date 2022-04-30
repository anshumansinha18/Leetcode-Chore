**APPROACHES**
​
1. Iterate three times to check if row is unique, if col is unique and lastly if a box is unique.
​
2. Iterate only one time. Use hash sets. Sets only contains unique value.
Eg: row = "r05", col="c15" box = "b05"
This is referring to value 5 in (0,1)
Use Formula: boxno = i/3*3 + j/3;
**3. Even better approach**: usedRow[9][9], usedCol[9][9], usedBox[9][9]
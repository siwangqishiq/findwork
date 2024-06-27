### 指定中心点缩放矩阵的推导

沿中心点 $P(c_x , c_y)$ 缩放 $scale$ (简写$s$) 大小 求变换矩阵 $M_{sc}$

1. 先将点 $P(c_x , c_y)$ 平移至原点$(0,0)$ 

    $$
    M_t = 
    \begin{bmatrix}
    1 & 0 & 0 \\
    0 & 1 & 0 \\
    -c_x & -c_y & 1\\
    \end{bmatrix}
    $$

2. 缩放矩阵
   $$
    M_s = 
    \begin{bmatrix}
    s & 0 & 0 \\
    0 & s & 0 \\
    0 & 0 & 1\\
    \end{bmatrix}
   $$
3. 平移回原有位置  原始$M_t$矩阵的逆矩阵
   $$
   M_t' = M_t^{-1} = 
   \begin{bmatrix}
    1 & 0 & 0 \\
    0 & 1 & 0 \\
    c_x & c_y & 1\\
    \end{bmatrix}
   $$

综上 
$$
M_{sc} = M_t * M_s * M_t^{-1} 
$$ 

$$
M_{sc} =   \begin{bmatrix}
    1 & 0 & 0 \\
    0 & 1 & 0 \\
    -c_x & -c_y & 1\\
    \end{bmatrix} 
    \begin{bmatrix}
    s & 0 & 0 \\
    0 & s & 0 \\
    0 & 0 & 1\\
    \end{bmatrix} 
    \begin{bmatrix}
    1 & 0 & 0 \\
    0 & 1 & 0 \\
    c_x & c_y & 1\\
    \end{bmatrix}
$$

$$
M_{sc} = \begin{bmatrix}
    s & 0 & 0 \\
    0 & s & 0 \\
    -s c_x & -s c_y & 1\\
    \end{bmatrix} 

     \begin{bmatrix}
    1 & 0 & 0 \\
    0 & 1 & 0 \\
    c_x & c_y & 1\\
    \end{bmatrix} 
$$ 

$$
M_{sc} = \begin{bmatrix}
    s & 0 & 0 \\
    0 & s & 0 \\
    c_x(1 - s) &  c_y( 1 - s) & 1\\
    \end{bmatrix} 
$$ 

### 验证 
中心点$(c_x, c_y)$应该再乘以此变换矩阵$M_{sc}$后并不发生改变

$$
(c_x , c_y , 1) * M{sc} = (c_x , c_y , 1) * 
\begin{bmatrix}
    s & 0 & 0 \\
    0 & s & 0 \\
    c_x(1 - s) &  c_y( 1 - s) & 1\\
    \end{bmatrix}  
    = (c_x , c_y , 1)

$$

### 结论 
并不需要再最后一个矩阵种乘以缩放系数 $scale$




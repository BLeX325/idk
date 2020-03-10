--1--
max3 :: Int -> Int -> Int -> Int
max3 x y z = max (max x y) z

--2--
min3 :: Int -> Int -> Int -> Int
min3 x y z = min (min x y) z

--3--
sort2 :: Int -> Int -> (Int,Int)
sort2 x y = (max x y, min x y)

--4--
--Функция возвращяет True, если оба зачения True
bothTrue :: Bool -> Bool -> Bool
bothTrue True x = x
--bothTrue True False = False
bothTrue _ _ = False
--bothTrue False False = False

--5--
solve2 :: Double -> Double -> (Bool,Double)
solve2 0 b = (False, 0.0)
solve2 a b = (True,b/a)

--6--
isParallel :: (Int,Int) -> (Int,Int) -> (Int,Int) -> (Int,Int) -> Bool
isParallel (x1,y1) (x2,y2) (x3,y3) (x4,y4) = (y2-y1)*(x4-x3) == (x2-x1)*(y4-y3)

--7--
isIncluded :: (Double, Double) -> Double -> (Double, Double) -> Double -> Bool
isIncluded (x1,y1) r1 (x2,y2) r2 = sqrt ((x1-x2)^2 + (y1-y2)^2) <= r1-r2

--8--
isRectangular :: (Double, Double) -> (Double, Double) -> (Double, Double) -> Bool
isRectangular (a,b) (c,d) (e,f) = if (c-a)*(e-a)+(d-b)*(f-b) == 0 || (a-c)*(e-c)+(b-d)*(f-d) == 0 || (a-e)*(c-e)+(b-f)*(d-f) == 0 then True else False

--9--
isTriangle :: Int -> Int -> Int -> Bool
isTriangle x y z = if z<(x+y) && z>(x-y) || x<(z+y) && x>(z-y) || y<(z+x) && y>(z-x) then True else False
--третья сторона должна быть меньше суммы двух других сторон и больше --их разности.

--10--
isSorted :: Double -> Double -> Double -> Bool
isSorted x y z = if (x>y && y>z) || (x<y && y<z) then True else False

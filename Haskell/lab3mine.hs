----------------------------------------------------------------------------------------------
data Product = Book String String | Casette String | Disk String String Int deriving (Eq,Show) 

fromJust :: Maybe a -> a 
fromJust (Just a) = a 

getTitle :: Product -> String 
getTitle (Book x _) = x 
getTitle (Casette x) = x 
getTitle (Disk x _ _) = x 

getTitles :: [Product] -> [String] 
getTitles = map getTitle 

isBook :: Product -> Bool 
isBook (Book _ _) = True 
isBook (Casette _) = False 
isBook (Disk _ _ _) = False 

bookAuthor :: Product -> String 
bookAuthor (Book _ x) = x 

bookAuthors :: [Product] -> [String] 
bookAuthors ps = map bookAuthor (filter isBook ps) 

lookupTitle :: String -> [Product] -> Maybe Product 
lookupTitle nam ps = if lst==[] then Nothing else Just $ head lst 
where lst=filter (\ p -> (getTitle p)==nam) ps 

lookupTitles :: [String] -> [Product] -> [Product] 
lookupTitles ss ps = map fromJust $ filter (\ mp -> not (mp == Nothing)) $ map (\ s -> lookupTitle s ps) ss 

— Проверка 

Main> lookupTitles ["s1","q","n1"] [Book "n1" "a1", Book "n2" "a2", Casette "n1", Disk "d1" "c1" 10] 
[Book "n1" "a1"] 
Main> lookupTitles ["k1","q","n1"] [Book "n1" "a1", Book "n2" "a2", Casette "k1", Disk "d1" "c1" 10] 
[Casette "k1",Book "n1" "a1"] 
Main> lookupTitles ["k1","d1","n1"] [Book "n1" "a1", Book "n2" "a2", Casette "k1", Disk "d1" "c1" 10] 
[Casette "k1",Disk "d1" "c1" 10,Book "n1" "a1"]
----------------------------------------------------------------------------------------------

data Book = Book String String
data Video = Video String 
data CDisk = CDisk String String Int
data Product = Product Book  Video CDisk 

--для разных товаров
class Titleable a where
  getTitle :: a ->String
instance Titleable Book where
  getTitle (Book title _) = title
instance Titleable Video where
  getTitle (Video title) = title
instance Titleable CDisk where
  getTitle(CDisk title _ _) = title

--получение тайтлов
getTitles (x:xs) = [ getTitle x | x<-xs ]

--получение товаров
lookupTitles (x:xs) (y:ys) = [y|x<-xs,y<-ys,x==lookupTitle y]

----------------------------------------------------------------------------------------------

data Product
    = Book {
        title   :: String ,
        author  :: String }
    | VideoTape {
        title   :: String }
    | CD {
        title   :: String ,
        artist  :: String ,
        records :: Int    }
    deriving (Show)

----------------------------------------------------------------------------------------------


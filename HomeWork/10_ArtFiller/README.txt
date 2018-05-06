CSCI/CMPE 2380
Recursion
For this assignment, make sure that you comment your source code adequately.
Your job is to write the fill function for a raster-based graphics program. The graphic is stored in a 2D array of
symbols. The input to the function is the row and column cell of the pixel (symbol) to be changed and what symbol to
change it to. The goal is to fill the enclosed shape (of one symbol) with the new symbol. This should be done
recursively.
The program should dynamically read in an ascii art file, then prompt the user for the cell to fill and what symbol to
fill it with. Then allow the user to save the new art.
Example run:
Select from the options: (L)oad art, (F)ill, (S)ave art
Choice? L
File to read: art.txt
               .<@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@>.             
            .<@@@@@@   $$$$$$$$$$$$$$$$$$$$$\^^^^^^/$$$$@@@>.          
         .<@@@@@<   .$$$$$'~       '~'$$$$$$$\  /$$$$$$>@@@@@>.       
      .<@@@@@<'   o$$$$$$                `'$$$$$$$$$$$$  '>@@@@@>.   
   .<@@@@@<'    o$$$$$$oo.                  )$$$$$$$$$$     '>@@@@@>.
   '<@@@@@<    o$$$$$$$$$$$.                                 >@@@@@>'
     '<@@@@<  o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$oooooo...    >@@@@>'  
       '@@@@< $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$)>@@@@>'    
         '<@@@@$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$@@@@>'      
           '<@@@@$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$@@@@>'        
             '<@@@@<    .oooo.                    .$$@@@@>'          
               '<@@@@oo$$$$$$$o..             ..o$$@@@@>'            
                 '<@@@@$$$$$$$$$$$$$oooooooo$$$$$@@@@>'              
                   '<@@@@'$$$$$$$$$$$$$$$$$$$$$@@@@>'                
                     '<@@@@<   ~"SSSSSS"~   >@@@@>'                  
                       '<@@@@<            >@@@@>'                    
                         '<@@@@<        >@@@@>'                      
                           '<@@@@<    >@@@@>'                        
                             '<@@@@<>@@@@>'                          
                               '<@@@@@@>'                            
                                 '<@@>'                              
 ^^ 
Select from the options: (L)oad art, (F)ill, (S)ave art
Choice? F
Cell to begin Fill:
Cell Row: 5
Cell Column: 27
Symbol: +
               .<@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@>.             
            .<@@@@@@   $$$$$$$$$$$$$$$$$$$$$\^^^^^^/$$$$@@@>.          
         .<@@@@@<   .$$$$$'~       '~'$$$$$$$\  /$$$$$$>@@@@@>.       
      .<@@@@@<'   o$$$$$$                `'$$$$$$$$$$$$  '>@@@@@>.   
   .<@@@@@<'    o$$$$$$oo.                  )$$$$$$$$$$     '>@@@@@>.
   '<@@@@@<    o$$$$$$$$$$$.                                 >@@@@@>'
     '<@@@@<  o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$oooooo...    >@@@@>'  
       '@@@@< $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$)>@@@@>'    
         '<@@@@$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$@@@@>'      
           '<@@@@$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$@@@@>'        
             '<@@@@<    .oooo.                    .$$@@@@>'          
               '<@@@@oo$$$$$$$o..             ..o$$@@@@>'            
                 '<@@@@$$$$$$$$$$$$$oooooooo$$$$$@@@@>'              
                   '<@@@@'$$$$$$$$$$$$$$$$$$$$$@@@@>'                
                     '<@@@@<   ~"SSSSSS"~   >@@@@>'                  
                       '<@@@@<            >@@@@>'                    
                         '<@@@@<        >@@@@>'                      
                           '<@@@@<    >@@@@>'                        
                             '<@@@@<>@@@@>'                          
                               '<@@@@@@>'                            
                                 '<@@>'                              
 ^^
Select from the options: (L)oad art, (F)ill, (S)ave art
Choice? S
File to write: artn.txt
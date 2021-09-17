#Julia Set

Creates a beautiful zooming julia set for your pleasure

## Some code obfuscation (Note, will not run)

include<stdlib.h>
include<stdio.h>
include<math.h>
                                                  type de f st                                      
                                                    r     u ct                                      
                                                            {                                       
                                                           dou                                      
                                                    ble     r                                       
                                              e  al    _   pa                                       
                                         r   t ;d     o                                             
                                            ub le          i                                        
                                         m  ag_p                        a                           
                                       r t   ;}c     o  mp          l e  x         _                
                                 n      umber;t      yped          e f  s  t     r                  
                                uc     t set{  in                t   n    rows    ;in               
                             t     n   cols;d                 ou ble m i n_real;d ou                
                              bl    e   max_real              ;double m in_i       m                
                                        ag;doubl             e  max_imag;c     o  m                 
                                p le    x_nu  mbe           r  c;complex_ n u   mb                  
                                e      r  **c   omp           lex_matrix; ch                        
                               ar        ***j               ulia_set;}SET;comp                      
                              le x    _  num b    e r    new  _complex(dou b   le    r              
                              eal_p  a  r t, d ouble i    mag_part){comp      l ex_nu               
                              mbe    r   temp;  temp.r    e  al_part = real  _ part;temp. i         
                              mag_    p  art    = ima        g _part;return temp;}SET  *   n        
                           e w _ set  (int nrow s, i nt      ncols, do  uble min_real,   d o        
                          u    b  le  max_re   al,   d    ouble m in_i m  ag, d ouble               
                                  max_imag){SET *te     mp = (str  uct         set *)m   a          
                            l loc( sizeof(struct se   t));temp ->    n       r  ow  s = nrows       
                            ;te  mp -> ncols = nco  ls;temp -> m    in_ r     eal  =  min_real;t    
                            emp -> max_real = max_ real;temp ->      min_      imag     = min       
                             _ imag;temp -> max_imag = max_im    a g ;tem      p -    >c =          
 n                       ew_  c omplex(-0.8,0.156);temp ->      j ulia_se   t   =      (c har       
*                          *  *)malloc(temp->nrows*sizeof (c         har*           *));   temp     
 -                         >  complex_matrix = (comp   le  x         _nu   mbe          r    ** )   
 m                          alloc(temp->nrows * size   o    f       (c                  ompl e x    
     _                        number*));for (int i =        0       ;                         i <   
   te mp -                  >nc ols; i++){temp->comple           x  _                      m atri   
 x[i] =                      (complex_number *)malloc(te   mp      -                         > n    
cols*si                      zeof(complex_number));temp- > j u   l  ia                       _  set 
[i] = (ch a                    r **)malloc(temp->ncols*sizeof(c   har*                         )   )
;}retur n tem               p   ;}void set_matrix(SET* set){dou                                  bl 
e  r eal_ste                  p =  (fabs(set->min_r ea l)+fabs(s                                et- 
  >m    ax_r  e                a l))/(set->ncols-         1);dou                        b        l  
 e im  ag  _ste p              =    (fabs(set->mi   n_  i mag)                      +fabs(se    t-> 
 max _  im   ag)                 )/(  set->nrows-1);     double                    real    _      i 
 t          r   =                 se t- >min   _real;    do uble                    i           mag 
     _     it  r =                       set   ->min_       i  m                    a    g; f    or 
               (int i                =   0;   i < set- > n     c                 ols;     i+    +)  
               { f               o    r  (  int j = 0;            j               <            set  
                  ->             n ro ws;      j++){se       t - >c              o      mp    lex_  
                mat                   rix      [i][j]         =                  new    _co  mple   
                   x(                 real_i tr,imag_ it                       r  )      ; r ea     
                  l_it                 r+= r  eal_step                          ;}re                
         a        l                             _itr = set  - >m                 in_ r              
       eal;i        m                 ag        _itr+= i  m ag_st               e  p                
    ;}} c   om    plex              _n  u       mber ad d    (compl              ex_nu              
    m b      e    r  a             ,  c o       mplex_nu    mber    b             ){c               
    om    pl      ex_nu             m        be r temp;tem p.r  e   a               l _ pa          
    rt     =       a.                 re     a   l_part+   b.r  e                  al_p  ar t       
   ;te           mp.                   ima  g _  part =    a.i ma  g_               par  t      +   
    b          .i mag_                pa  rt      ;return temp;}c  omp                 le x  _num   
   ber      sq uar                      e(com    p   lex_number c){ c  o              mplex _nu   mb
   er       te m p;                   temp.r e   a   l_part = (pow(c                   .r ea l    _p
    ar          t                      ,2)-pow(c.i  mag_part,2));temp .i                 m ag_par  t
    =                                  (2*c.real_part*c.imag_part);ret  ur                 n temp;}d
     o                          u  b   le absolute_complex(complex_nu   mb                 er   c){r
   eturn                        s q r  t(pow(c.real_part,2)+pow(c.imag_ p                      art,2
    ));                          }   v   oi d  delete_set(SET* set){for (                      i nt 
    i =  0;                              i      < set->ncols;i++){free(s   e                   t  ->
      ju  l                      i        a   _s et[i]);free(set->comple                    x_   m  
      atr i  x                  [i]       );   }  free(set->julia_set);  f                          
        r ee (            s     et        -   >   complex_matrix);set->juli                         
     a _se t  =N  U        L  L;s e       t- >complex_matrix=NULL;}int   it                         
       erate _z(c  o    m pl  ex_nu  m   b er z, SET *set, int itr){z =     s                       
         q u  ar    e( z)    ;z = ad     d (set->c,z);int count = 0;whi l e                         
        ( abso  l  ute_       com p  l  ex(z) < 2){ complex_number z_tem p                          
        =  squar  e(z);c     omple     x_number z_  temp_two = add(se   t->                         
         c,z_temp)  ;z      =   z_t   emp_two;count ++;if (count > itr) { r                         
           etu rn - 1;          }}return cou      nt;}void set_julia (S   E                         
             T   * set) {f or   (int  i = 0;    i   < se t->nrows ;   i   +                         
           +   ) {for (int j =  0; j < set->   n  c ols   ; j ++) {if      (                        
          i t    erate_z(set->complex_m          a tri  x[i][j ], set,8  0) !                       
          = - 1){set->ju  lia_set[i][j]          =       ;} e   ls   e {                            
           s  et->julia_s   et[i][j] = X;} }  } }void  print_juli a( SET                            
               *  set) {    f or (int i = 0; i     < s e  t->  n  r o  w                            
                 s  ;     i++){for (int j  =             0; j       < s                             
                          et->ncols; j++      )      {   pri  n                                     
                           t f(s,set->juli                a_ se       t                             
                  [i        ][j]);}prin  t            f(n  ewli      n                              
                 e);  }   } int main(){               SET* set    =                                 
                  n        e  w _set(10                0, 100,-   2   ,2                            
                  ,-   2, 2);   set                      _matrix  ( se                              
                  t);     s    et _j           u      l  ia(set)   ;prin                            
                  t _         j             ulia(     set) ; d      e   l                           
                             e             te    _      se  t(                                      
                                           s         e t);                                          
                                          f   r       ee ( se                                       
                                         t          ) ;                                             
                                          se  t  = NUL                                              
                                         L;                                                         
                                         } /                                                        
                                          // 
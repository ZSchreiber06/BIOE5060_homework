classdef BlackWhite2D
  properties (Access = private) % private members
      image0
  end 
  properties % public memebers
      mask
  end
  methods  % shifting main body of code into object
      function obj = BlackWhite2D(img_int, mask_int)  % class constructor/initalizer
          obj.image0 = img_int;
          if(nargin < 2)
              obj.mask = [0 1 0; 
                          1 1 1; 
                          0 1 0];
          else 
              obj.mask = mask_int;
          end 
      end 
          
      % Define set of functions associated with this object
 
      function output = grow(self, iternum, mask_int)
        if (nargin < 2)
            iternum = 1;
        
        end 
        if (nargin > 2)
            self.mask = mask_int;
        end 
        for iter = 1:iternum
            field0 = conv2(self.image0, self.mask, "same");
            logic_field = logical(field0);
            self.image0 = logic_field;
            output = logic_field;
        end
        
      end 
      function output = shrink(self, iternum, mask_int)
        if (nargin < 2)
            iternum = 1;
        end 
        if (nargin > 2)
            self.mask = mask_int;
        end 
        invert_image0 = ~self.image0;
          for iter = 1:iternum
             field0 = conv2(invert_image0, self.mask, "same");
             logic_field = logical(field0);
             invert_image0 = logic_field;
             output = ~logic_field;
          end
            
      end
  
    end 
end

# MiniTracker
 a mini sample-based hardware tracker


ORGANIZATIONAL STRUCTURE
  each lane is made up of patterns which are made up of step objects. 
  Each of these objects implement the Editable class allowing them to be accessible to human  input vis the device
  the Step objects contain information for the Lane sanpleplayer to use to play parts of the sample
    on/off
    the sample chop index (this determines start and stop positions)
    the pitch
    step fx (things like rolls, reverse, velocity, maybe lane instance fx)
  The lane object deal with playback.  
    Each lane can hold one instrument (sample) and can play back as slices or as whole
    the lane will also deal with all insert FX like filters, eq, reverb, distortion (basically anything that's in the Teensy Audio Library)
    The insert FX will be editable through a separate UI page 
  
UI DESIGN
 there will be several viewable pages
 1. Pattern view
    - here you will see the way each lane is sequenced
 2. Song view
    - here you will be able to string patterns together and edit things like master tempo
 3. Lane view
   - here you will be given several submenus that allow you to 
     - edit the sample slices
     - edit the sample
     - edit the insert FX of the lane
   - these will accesible through the buttons directly under the screen that normally correspond to selecting a lane


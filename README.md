# Editor-Buffer
 Implement the buffer of a (very simple) text editor.

Think of the data upon which a text editor operates as a sequence of characters, along
with an “insertion point” that indicates where the next change is to take place. The buffer is
the data structure that represents the text being edited, the location of the insertion point and
any other information that may be needed. The buffer supports operation such as insertion of a
character, deletion of a character next to the insertion point, moving the insertion point left or
right, etc.


The code for managing the buffer is typically independent of the code for managing the display
of the buffer contents (i.e., what the user actually sees). More accurately, an editor typically con-
sists of three components: the buffer, a view of the buffer (some sort of display), and a controller
that accepts user input. At a high level, the controller is really an infinite loop that executes the
following steps, where the buffer is initially empty:

(1) Update the view, which will display the text in the buffer, along with an indication of the
location of the insertion point (often by a vertical bar between two of the characters in the
text).

(2) Wait for an event that indicates that the user wishes to change the buffer. Typical events
are a key press of an ordinary character (indicating that the user wishes to insert a character
into the buffer), a key press of the backspace or delete key (indicating that the user wishes
to delete a character from the buffer), or a key press of an arrow key (indicating that the
user wishes to change the position at which the next event will affect the buffer).

(3) Modify the buffer according to the event.
The driver program provided in the code distribution implements a text-based version of a con-
troller and view by presenting the user with a menu of options (like insert a character, delete the
character to the left of the insertion point, etc.) and displaying the contents of the buffer as a
string. Provided you implement an appropriate set of functions for modifying and querying the
buffer, neither the controller nor the view need to know anything about how the text and insertion
point are actually represented. Your job is to implement the buffer structure and that appropriate
set of functions. In a bit more detail, you will implement the following:

• A buffer structure that has at least one field: an array of char values. You will almost
certainly have other fields (see below).

• An insertion function that inserts a new character into the buffer at the current insertion
point.

• Two deletion functions that delete the character to the left or right of the current insertion
point.

• Two functions to move the insertion point to the left and the right.

• A function to set the insertion point to a specific position.
• A function that takes a buffer and two char arrays as parameters, and fills one of the arrays
with the contents to the left of the insertion mark and the other with the contents to the
right of the insertion point. The view uses this function to display the contents of the buffer
and the insertion point.

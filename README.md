# MapBuilder2

This is a project based on random generation. It randomly generates a World that holds randomly generated Lands that holds randomly generated Maps that will have different randomly generated layouts with randomly generated Rooms.

The World is traversable by moving around square by square.

Because of how the console is manipulated, this project in Windows specific.

It prints out 50x200 characters to the screen to show the map, and will smartly refresh the characters it needs to. The way it is done is the maptile will keep track when it is updated, and then once it's time to refresh the screen, it will move the console's cursor to after the maptile to refresh, backspace to delete it, then print the new character. This makes refreshing the screen a lot faster, but when you move to a new map it will slow down to refresh the whole thing.

TODO:

Different types of movement and teleportation. (Bunnyhopping is implemented, press space to keep momentum).

The character you control will have a variety of skills that will be learned from randomly generated NPCs once you have skill enough in them. These skills include spells, melee, archery, as well as a variety of passives.

Randomly generated mob spawns will allow for the player to fight and farm for mats to craft gear at randomly generated crafting stations. Different parts of the world will have different types of mob spawns that will drop different mats needed for the variety of gear.

This gear will build your character to allow him to descend into procedurally generated dungeons.

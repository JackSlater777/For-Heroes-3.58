

                 ************** Difficulty Mod ****************
                 ************** version: 1.031 ******************
                 ************  Daemon & Perry  **************
                 

A mod to customize game difficulty with many options to select at game start.

The mod has to offer (all optional):

-Options for stronger computer players
-Artifact equipment mod for AI
-Increase neutral stack size
-Increase neutral growth
-Neutral stacks can grow over 4000
-Increased stats of neutrals over time
-Extra growth for low-level troops
-Random spell buffs for neutrals
-Random abilities for neutrals (temporary disbaled)   
-Battle commander option
-Battle rewards option
-Tougher Karmic Battles
-Always Random Hero
-Progressive difficulty option
-AI starting boost
-AI no Dimension Door spell
-Option interface for Mixed Neutrals Mod by Berserker



How to play with this mod:
- Select the options you like at map start
- Additional informations are available on right-clicking 
- Clicking "Confirm" will save all your settings, Clicking "Cancel" will reset all your options
- Enter a day at which the AI starts to receive bonuses (Payday) This will allow you to built up your hero
- Dont use the highest AI difficulty when you are new to this mod, start with Easy or Normal and Payday at day 50
- If you want, also use progressive-difficulty option to change the AI level during the game to a harder one. This allows for a smooth game progression. Like from Hard to Expert. Or from Extreme to Insane.
- Better dont use Insane settings
- Game to easy or to difficult? No problem, make NEW settings during your game by right-clicking the system icon on the adventure map


Maybe frequently asked questions
 
- Which WoG settings can I use?
Answer: Feel free to use any setting you like. The mod will automatically activate the option it needs if you select them.

- I want to customize some values for AI bonus, can I?
Answer: Sure, if you know what to edit you can change anything you like, but better ask Perry or Daemon for help.

- Why are some values and bonuses so absurd?
Answer: Heroes 3 is a manifold game, people play it differently, different maps and mods, a value you think is crazy might just be okay for the other guys, or maybe it is the other way around. That's when we start modding.

- What is the Mixed Neutral Configuration Option?
Answer: The Mixed Neutral mod does what the name suggests. It mixes neutral stacks to give more diversity in fights. The mod was developed by Berserker and must be downloaded separately. The difficulty mod only provides a convenient window to make all settings.

- Why do I get some strange error message when I start my game?
Answer: You probably have an outdated version of the ERA. You need at least ERA 3.3 and the ERA-erm-Framework mod to run the Difficulty mod with full functionality. 


This mod also includes the AI Artifact Equipment Mod:
If possible AI will always equip the best artifact for every slot. This script checks the artifacts of AI heroes every day and equips better ones if available in a backpack.
You can conduct the priority order for equipping by reading the code. The lower an artifact is the higher the priority. This mod alone makes the AI much stronger without cheating.

Visit Homepage: http://heroescommunity.com or http://wforum.heroes35.net for Updates.


Changelog:

1.031

- Increasing Stack Size option at map start works again
- removed SN:D from 40 wog - karmic battles.erm 
- Mixed Neutrals Mod enable/disable is now saved when restarting the map
- some minor changes


1.03

- Added a new configuration window for Mixing Neutrals Mod, which allows to easily customize nearly all options. Open it by activating the Mixed Neutral Config option.
- SAVE function for all settings! Settings are transferred even if you close your game. Thanks to Berserker.
- AI Artifact Equipment option can now be enabled/disabled. 
- Added small Heroes 3 fonts so that all text fits in the text fields and does not overflow. If you don't want to change your font delete the file in the Data folder.
- The "Upgrade Neutrals Slowly" option now works also with the Third Upgrade mod.
- The mod requires now ERA 3. If you want to run the mod under ERA 2.9x delete the file "difm - era 3.erm" from the Data/s folder, you'll loose a few features. 
- Mod is no longer dependant on WoG scripts.
- Updated WoG Script 6 wog - random hero, 40 wog - karmic battles and 21 wog - neutral units. (thanks to Archer)



1.02

- New options for Dif Mod

"AI_Recover_Losses":				"{AI Recover Losses}
			
									The computer player recovers {50%} of any lost units in combat vs neutral stacks. If a unit is killed completely it will not be recovered.",	

"AI_Compensation":					"{AI Compensation}
			
									To give the AI a better start each owned hero gets additional units at day one and additional units to recruit in towns. The amount of additional units depends on the option {Neutral Stack Size} and {Double Stack Size}.
									The hero only gets level 1-3 units and not if he already has above 100 units in one slot. This option helps to solve the problem that the computer was sometimes unable to defeat the big stacks that could be generated at map start. The amount of additional units is roughly the same as the Stack Size option adds units to neutral stacks.",

"AI_Useful_Spells":					"{AI Useful Spells}
			
									When the Payday is reached each AI hero will get a spell book and the following spells for free: {Haste}, {Slow}, {Cure} and {Curse}",

"AI_has_no_DD":						"{AI no Dimension Door}
			
									To avoid lag on big maps the Dimension Door spells for all computer players will be replaced to fly. This should reduce loading time for AI between rounds.",



- fix Neutral Stat gain not working
- fix clicking on Insane Dif would reset current AI-Level selection 
- Insane level now selectable from start and Progressive Difficulty moved as separate option (less confusing)
- If Monsters are replaced with Dif Mod Uptier Option they now will not be set to aggressive
- If Stack size is added to neutrals they now will not be set to "Never join" if they were supposed to "Always join"
- Reduced the power of the AI commander on all levels by reducing his damage by ~50%
- added some new hint texts
- fix Neutral Stack Experience Option was disabled by default


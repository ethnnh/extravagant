CROPS = 3
SIZE = get_world_size()

clear()
do_a_flip()
while True:
    for i in range(0, SIZE):
        for i in range(0, SIZE):
            if can_harvest():
                harvest()
                if get_pos_x() == 0:
                	harvest()
                	move(North)
                elif get_pos_x() == 1:
	                if (get_pos_x() + get_pos_y()) % 2 == 1:
		                plant(Entities.Tree)
		                move(North)
                	else: 
		                plant(Entities.Bush)
		                move(North)
                else:
                	if get_ground_type() != Grounds.Soil:
                    till()
                if get_entity_type() == None:
                    	trade(Items.Carrot_Seed)
                        plant(Entities.Carrots)
                        move(North)
            else:
                move(North)
        move(East)
    do_a_flip()    


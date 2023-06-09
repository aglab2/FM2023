#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"


/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/cozies/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_cozies_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x7, _cozies_segment_7SegmentRomStart, _cozies_segment_7SegmentRomEnd), 
	LOAD_YAY0(0xa, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario),

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, cozies_area_1),
		WARP_NODE(0x0A, LEVEL_COZIES, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_COZIES, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_COZIES, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MOVING_PLATFORM_WITH_ACTS(funny_platform_cozies_geo, funny_platform_cozies_collision, 1659, 34, 872, 0, 0, 0, (SPLINE_OBJECT_BHV_AUTO << 24) | (SPLINE_OBJECT_MOVE_BACK_AND_FORTH << 16) | (12 << 8), bhvSplinePlatform, 31),
		MARIO_POS(0x01, 0, 0, 100, 0),
		OBJECT(MODEL_NONE, 0, 100, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(cozies_area_1_collision),
		ROOMS(cozies_area_1_collision_rooms),
		MACRO_OBJECTS(cozies_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		AREA_SPLINE(cozies_area_1_spline_funny_platform_path),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 100, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};

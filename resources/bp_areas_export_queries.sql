// Downscale resolution
UPDATE bp_areas
SET geojson = TO_JSON(
    ST_AsGeoJSON(
        ST_MakeValid(
            ST_RemoveRepeatedPoints(
                ST_GeomFromGeoJSON(
                    ST_AsGeoJSON(the_geom,9)
                )
            )
        )
    )     
);

// Csv export
SELECT 
    gid, 
    CASE 
        WHEN 
            type = 'Nature' 
        THEN 
            CONCAT(locality, ' (',  source, ')') 
        ELSE
            locality 
    END 
        AS locality,
    geojson,
    iso,
    source,
    type,
    locality_nl
FROM bp_areas;
